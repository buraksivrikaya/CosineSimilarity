#ifndef CosSimilarity
#define CosSimilarity
void printMatrix(int docCount, char* fileNames[docCount], Node* eliminatedWords, int finalMatrix[][length(eliminatedWords)]);
void calcSim(int fileCount, char* fileNames[fileCount],int simWordsCount, int docTermMatrix[][simWordsCount]);
#endif
