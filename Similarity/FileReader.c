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
           //printf("-found file : %s\n", file->d_name);
	   fileNames[docCount] = file->d_name;
           docCount++;
	  
        }
    }
    closedir(directory);

    printf("-found %d txt files...\n", docCount);

    for(int i=0; i<docCount; i++){
        //printf("NAME OF THE FILE : %s\n",fileNames[i]);
 		
           char* wordsX[10000];
           FILE * fp;
	   char * line = NULL;
	   size_t len = 0;
	   ssize_t read;
	   Node* r = newNode();
	   fp = fopen(fileNames[i], "r");
	   if (fp == NULL)
		exit(EXIT_FAILURE);

	   while ((read = getline(&line, &len, fp)) != -1) {
		char* pch;
		
		pch = strtok (line," ,.-()\r\n\t");
		while (pch != NULL)
		{
		  printf ("%s-",pch);
		  int i=0;
		  for(; pch[i]; i++){
	             pch[i] = tolower(pch[i]);
		  }
                  insertFirst(r,(char*) pch,1);
		  pch = strtok (NULL, " ,.-()\r\n\t");
		}
	   }
           printList(r);
	   fileWords[i] = r;
	   fclose(fp);
	   if (line)
		free(line);
    }
    int i = 0;//docCount can be used here
    Node* allWords = newNode();
    while(fileWords[i] != NULL){
	struct Node *ptr = fileWords[i]->head;
	while(ptr != NULL) {
	   printf("(%s,%d) ",ptr->word,ptr->count);
	   if(find(allWords, ptr->word)){
		Node* temp = find(allWords,ptr->word);
		int count = temp->count + ptr->count;
		insertFirst(allWords, ptr->word, count);
	   }
	   ptr = ptr->next;
	}

	i++;
    }
}
