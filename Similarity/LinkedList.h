struct node {
   int data;
   char* key;
   struct node *next;
};
void printList();
void insertFirst(char* key, int data)
