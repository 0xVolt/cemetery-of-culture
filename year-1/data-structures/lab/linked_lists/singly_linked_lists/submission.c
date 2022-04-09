/* Code by Desh Iyer
-> Implementation of singly linked-lists using a menu driven program having 
-> Insertion and Deleting at Beginning 
-> Insertion and Deleting at End
-> Traversing and Displaying linked-list */

#include <stdio.h>
#include <stdlib.h> /* For dynamic memory allocation */

// we can use typedef to make the code easier to understand
struct node {
    int data;
    struct node *next;
};

struct node *headNode = NULL;

/* Functions declarations */
void menu();
void traverseList();
void insertBeg(struct node *);
void insertEnd(struct node *);
void deleteBeg();
void deleteEnd();

/* Driver function */
int main() {
    menu();

    return 0;
}

/* Menu driven functionality */
void menu() {
    struct node *newNode;
    int choice;
    
    for (;;) {
        system("cls");
        
        printf("--------------M E N U--------------\n\n");
        printf("1. Display List\n");
        printf("2. INSERT at Beginning\n");
        printf("3. INSERT at End\n");
        printf("4. DELETE at Beginning\n");
        printf("5. DELETE at End\n");
        printf("6. Quit\n\n");

        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                traverseList();
                break;
            
            case 2:
                newNode = (struct node *)malloc(sizeof(struct node));
                printf("\nEnter the data for the first node \n");
                scanf("%d", &newNode->data);
                insertBeg(newNode);
                break;

            case 3:
                newNode = (struct node *)malloc(sizeof(struct node));
                printf("\nEnter the data for the first node \n");
                scanf("%d", &newNode->data);
                insertEnd(newNode);
                break;

            case 4:
                deleteBeg();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid response!\n\n");
        }

        printf("\n");
        system("pause");
    }
    
}

/* Function to traverse the linked-list */
void traverseList() {
    struct node *tempNode;

    tempNode = headNode;

    if (headNode == NULL) {
        printf("No nodes to display!");
        return;
    }
    else {
        printf("\n");
        while(tempNode != NULL) {
            printf("%d --> ", tempNode->data);
            tempNode = tempNode->next;
        }

        printf("NULL");
    }
}

/* Function to insert a new node at the beginning of the linked-list */
void insertBeg(struct node *newNode){
    newNode->next = NULL;

    if(headNode == NULL)
        headNode = newNode;
    else {
        newNode->next = headNode;
        headNode = newNode;
    }
}

/* Function to insert a new node at the end of the linked-list */
void insertEnd(struct node *newNode) {
    struct node *tempNode;

    newNode->next = NULL;
    tempNode = headNode;
    
    if (headNode == NULL) {
        headNode = tempNode;
    } else {
        while(tempNode->next != NULL) {
            tempNode = tempNode->next;
        }

        tempNode->next = newNode;
    }
}

/* Function to delete the node at the end of the linked-list */
void deleteBeg() {
    if (headNode == NULL) {
        printf("No nodes to delete!");
        return;
    }
    else {
        headNode = headNode->next;
    }
}

/* Function to delete the node at the beginning of the linked-list */
void deleteEnd() {
    struct node *currNode,*nextNode;
        
    currNode = nextNode = headNode;
    
    if (headNode == NULL) {
        printf("No nodes to delete!");
        return;
    } else {
        while(nextNode->next != NULL) {
            currNode = nextNode;
            nextNode = nextNode->next;
        }

        if(nextNode == NULL) {
            headNode = NULL;
        } else {
            currNode->next = NULL;
        }
    }
}