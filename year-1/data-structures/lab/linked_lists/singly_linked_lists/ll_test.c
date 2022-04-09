#include <stdio.h>
#include <stdlib.h>

// typedef can be used to make code easier to understand
struct node {
    int data;
    struct node *next;
};

struct node *headNode = NULL;

// Functions declarations
void menu();
void createList();
void displayList();
void insertBeg();
void insertEnd();
void deleteBeg();
void deleteEnd();

void Middle(struct node *head) 
{ 
    struct node *slow = head; 
    struct node *fast = head; 

    if (head!=NULL) 
    { 
        while (fast != NULL && fast->next != NULL) 
        { 
            fast = fast->next->next;
            slow = slow->next; 
        } 
    } 
    printf("The middle element is %d\n\n", slow->data); 
}


int main() {
    createList();
    Middle(headNode);
    // displayList();
    
    // menu();

    return 0;
}

void menu() {
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
                displayList();
                break;
            
            case 2:
                insertBeg();
                break;

            case 3:
                insertEnd();
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

void createList() {
    struct node *currNode, *tempNode;
    int n;
    printf("\nEnter the number of nodes to insert\n");
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        currNode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data for node %d: ", (i+1));
        scanf("%d", &currNode->data);
        if(i==0)
        {
            headNode=tempNode=currNode;
        }
        else
        {
            tempNode->next = currNode;
            tempNode=currNode;    
        }
        tempNode->next=NULL;
    }
}

void displayList() {
    struct node *tempNode;

    tempNode = headNode;

    if (headNode == NULL) {
        printf("No nodes to display!");
        return;
    }
    else {
        printf("\n");
        while(tempNode != NULL) {
            printf("%d ", tempNode->data);
            tempNode = tempNode->next;
        }
    }
}

void insertBeg(){
    struct node *newNode;
    newNode =(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data for the first node \n");
    scanf("%d", &newNode->data);

    if(headNode==NULL)
        headNode=newNode;
    else {
        newNode->next=headNode;
        headNode=newNode;
    }
}

void insertEnd() {
    struct node *newNode, *tempNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &newNode->data);
    
    newNode->next = NULL; // Make sure the node entered is last node in ll
    tempNode = headNode; // Use to traverse
    
    if (headNode == NULL) {
        headNode = tempNode;
    }


    while(tempNode->next != NULL) {
        tempNode = tempNode->next;
    }
    tempNode->next = newNode;
}

void deleteBeg() {
    if (headNode == NULL) {
        printf("No nodes to delete!");
        return;
    }
    else
    {
        headNode=headNode->next;
    }
}

void deleteEnd() {
    struct node *currNode,*nextNode;
        currNode=nextNode=headNode;
    if (headNode == NULL) {
        printf("No nodes to delete!");
        return;
    }
    else 
    {
        while(nextNode->next!=NULL)
        {
            currNode=nextNode;
            nextNode=nextNode->next;
        }

        if(nextNode==NULL)
        {
            headNode=NULL;
        }
        else
        {
            currNode->next = NULL;
        }
    }

}