/*
 * CosSimilarity.c
 *
 *  Created on: Aug 16, 2017
 *      Author: buraks
 */
#ifndef LinkedList
#define LinkedList

#include <stdbool.h>
typedef struct Node
{
   char* word;
   int count;
   struct Node *next;
   struct Node *head;
   struct Node *current;
} Node;
struct Node* find(Node* r, char* word);
void printList(Node* r);
void printListWords(Node* r);
Node* newNode();
void insertFirst(Node* r, char* word, int count);
bool isEmpty(Node* r);
int length(Node* r);

#endif
