#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   char* key;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//display the list
void printList() {
   struct node *ptr = head;
   printf("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("(%s,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

//insert link at the first location
void insertFirst(char* key, int data) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));

   strcpy(&link->key, &key);
   link->data = data;
	
   //point it to old first node
   link->next = head;
	
   //point first to new first node
   head = link;
}

//is list empty
bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

//find a link with given key
struct node* find(char* key) {

   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(strcmp(&current->key, &key)!=0) {
	
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

main() {
   insertFirst("1231",10);
   insertFirst("2asda",20);
   insertFirst("asdgq3",30);
   insertFirst("4wqwqe",1);
   insertFirst("qweqw5",40);
   insertFirst("safq6",56); 

   printf("IsEmpty/Length %d/%d: ", isEmpty(), length()); 
	
   //print list
   printList();

   if(find("safq6")==NULL){
	printf("\nnot in list\n");
   }else{
	printf("\nin list\n");	
}
}
 
