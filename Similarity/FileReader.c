#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"

int main () {
    const char* path = ".";
    DIR *directory;
    struct dirent* file;
    FILE *tempFile;

    directory = opendir(path);
    
    if (directory == NULL) {
        printf("Error\n");
        exit(1);
    }

    
    while ((file=readdir(directory)) != NULL) {
        if(strstr(file->d_name, ".txt") != NULL){
           printf("--reading file : %s\n", file->d_name);
           FILE * fp;
	   char * line = NULL;
	   size_t len = 0;
	   ssize_t read;

	   fp = fopen(file->d_name, "r");
	   if (fp == NULL)
		exit(EXIT_FAILURE);

	   while ((read = getline(&line, &len, fp)) != -1) {
		char * pch;
		pch = strtok (line," ,.-()\r\n\t");
		while (pch != NULL)
		{
		  printf ("%s\n",pch);
		  pch = strtok (NULL, " ,.-()\r\n\t");
		}
	   }

	   fclose(fp);
	   if (line)
		free(line);
        }
    }
    closedir(directory);
}
