/*
 * CosSimilarity.c
 *
 *  Created on: Aug 15, 2017
 *      Author: buraks
 */

#include <stdio.h>
#include <math.h>

#include "LinkedList.h"

/* constant test variables
 */
/*
const int TEST_RUN = 1;
const int TEST_CONST_FILECOUNT = 3;
const int TEST_CONST_SIMWORDSCOUNT = 5;
*/
/* fileCount : number of files that determines rows
 * simWordsCount : nuber of words that pass 10 > term_count >= number_of_files
 */
void printMatrix(int docCount, char* fileNames[docCount], Node* eliminatedWords, int finalMatrix[][length(eliminatedWords)]){
	printf("-Matrix to compare :\n");
	printf("FILE\\WORDS: ");
	printListWords(eliminatedWords);
	for(int k = 0; k < docCount; k++){
		printf("%s ",fileNames[k]);
		for(int l = 0; l < length(eliminatedWords); l++){
			printf(" %d ", finalMatrix[k][l]);
		}
		printf("\n");
	}
	printf("\n");
}

/*
 * cos similarity calculation
 */
void calcSim(int fileCount, char* fileNames[fileCount],int simWordsCount, int docTermMatrix[][simWordsCount]){

    for(int f = 0; f < fileCount; f++){
    	int f1 = f;
    	int f2 = (f + 1)%fileCount;

        double dotProduct = 0;
        double normA = 0;
        double normB = 0;

        for(int i = 0; i < simWordsCount; i++) {
            dotProduct += (double) docTermMatrix[f1][i] * docTermMatrix[f2][i];
            normA += (double) docTermMatrix[f1][i]*docTermMatrix[f1][i];
            normB += (double) docTermMatrix[f2][i]*docTermMatrix[f2][i];
        }
        double result = dotProduct / (sqrt(normA) * sqrt(normB));
        printf("%s - %s similarity = %f \n", fileNames[f1], fileNames[f2], result);
    }
}
/*
 * TEST FOR COS SIMILARITY
 * */
/*
int main(void)
{
	if(TEST_RUN){
		int docTermMatrix[TEST_CONST_FILECOUNT][TEST_CONST_SIMWORDSCOUNT];

		for(int i = 0; i < TEST_CONST_FILECOUNT; i++){
			for(int j = 0; i < TEST_CONST_SIMWORDSCOUNT; j++){
				int temp = i + j;
				if(temp < TEST_CONST_FILECOUNT){
					temp = TEST_CONST_FILECOUNT + temp;
				}
				docTermMatrix[i][j] = temp%10;
			}
		}

		printf("test similarity start\n");
		printf("test similarity matrix is:\n");
		printMatrix(TEST_CONST_FILECOUNT, TEST_CONST_SIMWORDSCOUNT, docTermMatrix);
		printf("test cos similarity function\n");
		printf("test cos similarity function result\n");
		calcSim(TEST_CONST_FILECOUNT, TEST_CONST_SIMWORDSCOUNT, docTermMatrix);
		printf("test similarity end\n");

		printf("TEST 2 START--------\n");
		int matris2[3][5] = {{1,2,2,1,1},{1,1,1,1,1},{1,1,1,1,1}};

		calcSim(3,5,matris2);
		printf("TEST 2 END----------\n");

	}
	return 1;
}*/
