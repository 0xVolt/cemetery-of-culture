#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
   int data;
   struct Node *next;
} *front = NULL, *rear = NULL;

void insert(int);
void delete();
void display();

void main()
{
   int choice, value;
   system("cls");
   while(1) {
    printf("\nM E N U\n");
    printf("1. Insert element into the Queue\n2. Delete element from the Queue\n3. Display Queue\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1: 
            printf("Enter the value to be insert: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2: 
            delete(); 
            break;
        case 3: 
            display(); 
            break;
        case 4: 
            exit(0);
        default: 
            printf("\nInvalid option selected! Please try again!!!\n");
      }
   }
}

void insert(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if(front == NULL)
        front = rear = newNode;
    else {
        rear -> next = newNode;
        rear = newNode;
    }
    printf("\nInsertion is Success!!!\n");
}

void delete()
{
   if(front == NULL)
      printf("\nQueue is Empty!!!\n");
   else{
      struct Node *temp = front;
      front = front -> next;
      printf("\nDeleted element: %d\n", temp->data);
      free(temp);
   }
}

void display()
{
   if(front == NULL)
      printf("\nQueue is Empty!!!\n");
   else{
      struct Node *temp = front;
      while(temp->next != NULL){
	 printf("%d--->",temp->data);
	 temp = temp -> next;
      }
      printf("%d--->NULL\n",temp->data);
   }
}