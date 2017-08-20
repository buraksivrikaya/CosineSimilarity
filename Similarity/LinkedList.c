/*
 * CosSimilarity.c
 *
 *  Created on: Aug 16, 2017
 *      Author: buraks
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"

void printList(Node* r) {
   struct Node *ptr = r->head;
   printf("\n[ ");

   while(ptr != NULL) {
      printf("(%s,%d) ",ptr->word,ptr->count);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

Node* newNode(){
   struct Node *r = (struct Node*) malloc(sizeof(struct Node));
   r->head = NULL;
   r->current = NULL;
   return r;
}

void insertFirst(Node* r, char* word, int count){
   if(find(r, word)){
       struct Node* temp = find(r,word);
       temp->count += count;
   }
   else{
      struct Node *link = (struct Node*) malloc(sizeof(struct Node));
      link->word = malloc(strlen(word)+1);
      strcpy(link->word, word);
      link->count = count;
      link->next = r->head;
      r->head = link;
   }
}

bool isEmpty(Node* r){
   return r->head == NULL;
}

int length(Node* r) {
   int length = 0;
   struct Node *current;
	
   for(current = r->head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

struct Node* find(Node* r, char* word) {

   //start from the first link
   struct Node* current = r->head;

   //if list is empty
   if(r->head == NULL) {
      return NULL;
   }

   //navigate through list
   while(strcmp(current->word, word)!=0) {
	
      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }      
	
   //if data found, return the current Link
   return current;
}
/*
int main(void)
{
   Node* test = newNode();
   insertFirst(test, "31231asd", 1);

   insertFirst(test, "q3as31asd", 1);

   insertFirst(test, "bsd31231asd", 1);
   insertFirst(test, "bsd31231asd", 1);
   printList(test);
   if(find(test, "bsd31231asd")){printf("\nfound\n");}else{printf("\nnotfound\n");}
   //insertFirst(test, "asdas", 12);

}*/
