/*
 * CosSimilarity.c
 *
 *  Created on: Aug 15, 2017
 *      Author: buraks
 */

#include <stdio.h>
#include <math.h>

/* constant test variables
 */
const int TEST_RUN = 1;
const int TEST_CONST_FILECOUNT = 3;
const int TEST_CONST_SIMWORDSCOUNT = 5;

/* fileCount : number of files that determines rows
 * simWordsCount : nuber of words that pass 10 > term_count >= number_of_files
 */
void printMatrix(int fileCount, int simWordsCount, int docTermMatrix[][simWordsCount]){
	for(int i = 0; i < fileCount; i++){
		for(int j = 0; j < simWordsCount; j++){
			printf("%d ", docTermMatrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/*
 * cos similarity calculation
 */
void calcSim(int fileCount, int simWordsCount, int docTermMatrix[][simWordsCount]){

    for(int f = 0; f < fileCount; f++){
    	int f1 = f;
    	int f2 = (f + 1)%fileCount;

        int dotProduct = 0;
        int normA = 0;
        int normB = 0;

        for(int i = 0; i < simWordsCount; i++) {
            dotProduct += docTermMatrix[f1][i] * docTermMatrix[f2][i];
            normA += docTermMatrix[f1][i]*docTermMatrix[f1][i];
            normB += docTermMatrix[f2][i]*docTermMatrix[f2][i];
        }
        double result = dotProduct / (sqrt(normA) * sqrt(normB));
        printf("%d - %d similarity = %f \n", f1, f2, result);
    }
}
/*
 * TEST FOR COS SIMILARITY
 * */
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
}
