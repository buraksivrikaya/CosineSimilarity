/*
 * CosSimilarity.c
 *
 *  Created on: Aug 17, 2017
 *      Author: buraks
 */
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "LinkedList.h"
#include "CosSimilarity.h"

/* fileCount : number of files that determines rows
 * simWordsCount : nuber of words that pass 10 > term_count >= number_of_files
 */


/*
 * cos similarity calculation
 */



int main () {
    const char* path = ".";
    DIR *directory;
    struct dirent* file;
    FILE *tempFile;
    directory = opendir(path);
    int docCount = 0;
    char* fileNames[100];//maximum 100 files are allowed
    Node* fileWords[100];
    if (directory == NULL) {
        printf("Error\n");
        exit(1);
    }
    
    while ((file=readdir(directory)) != NULL) {
        if(strstr(file->d_name, ".txt") != NULL){
           printf("-Found file : %s\n", file->d_name);
			fileNames[docCount] = malloc(strlen(file->d_name)+1);
			strcpy(fileNames[docCount],file->d_name);
			docCount++;	  
        }
    }
    closedir(directory);

    printf("-Found %d txt files\n", docCount);

    for(int i=0; i<docCount; i++){
       //printf("-Reading file : \"%s\"\n",fileNames[i]);
 		
       FILE * fp;
	   char * line = NULL;
	   size_t len = 0;
	   ssize_t read;
	   Node* r = newNode();
	   fp = fopen(fileNames[i], "r");
	   if (fp == NULL){
		exit(EXIT_FAILURE);
	   }
	   while ((read = getline(&line, &len, fp)) != -1) {
		char* pch;
		
		pch = strtok (line," ,.-()\r\n\t");
		while (pch != NULL)
		{
		  //printf ("%s-",pch);
		  
		  for(int j=0; pch[j]; j++){
	             pch[j] = tolower(pch[j]);
		  }
          insertFirst(r,(char*) pch,1);
		  pch = strtok (NULL, " ,.-()\r\n\t");
		}
	   }
       
	   fileWords[i] = r;
	   fclose(fp);
	   if (line){
		free(line);
	   }
		
       //printf("-Finished reading file : \"%s\"\n",fileNames[i]);
       printf("-Words of \"%s\"  are:\n",fileNames[i]);
	   printList(r);
    }
/*
	int nC = 0;
	while(nC < docCount){
		printf("FILE : %s\n",fileNames[nC]);
		nC++;
	}*/

    int i = 0;
    Node* allWords = newNode();
    while(i < docCount){//docCount can be used here
		Node *ptr = fileWords[i]->head;
		while(ptr != NULL) {
			//printf("(%s,%d) ",ptr->word,ptr->count);
			insertFirst(allWords, ptr->word, ptr->count);			
			ptr = ptr->next;
		}
		i++;
    }
	printf("-All words count : %d\n", length(allWords));
	printf("-All words : \n");
	printList(allWords);
/*
* Eliminating words that doesn't ensure
* wordCount(i) | 10 > wordCount(i) >= docCount
*/
	
    Node* eliminatedWords = newNode();
	Node *ptr = allWords->head;
	int eliminatedWordCount = 0;

	while(ptr != NULL) {
		if(ptr->count >= docCount && ptr->count < 10){
			insertFirst(eliminatedWords, ptr->word, ptr->count);
			eliminatedWordCount++;
		}
		
		ptr = ptr->next;
	}

	printf("-Word elimination rule : 10 > word.count >= txtFileCount\n");
	printf("-Eliminated word count : %d\n", eliminatedWordCount);
	printf("-Eliminated words : \n");
	printList(eliminatedWords);
/*
* Creating matrix
*/
	int finalMatrix[docCount][eliminatedWordCount];
	ptr = eliminatedWords->head;
	int matrixWordIndex = 0;
	while(ptr != NULL) {
		for(int d = 0; d < docCount; d++){
			Node* temp = find(fileWords[d], ptr->word);	
			if(temp){
				finalMatrix[d][matrixWordIndex] = temp->count;
			}
			else{
				finalMatrix[d][matrixWordIndex] = 0;
			}
		}
		matrixWordIndex++;
		ptr = ptr->next;
	}
printMatrix(docCount, fileNames, eliminatedWords, finalMatrix);
/*
* Calculate Cosine Similarity
*/
	calcSim(docCount, fileNames, length(eliminatedWords), finalMatrix);
}
