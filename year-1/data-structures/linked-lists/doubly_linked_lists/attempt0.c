#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void createList(int);
void displayList();
void traverseRev();
void insertBeg(struct node *);
void insertEnd(struct node *);
void deleteBeg();
void deleteEnd();
void menu();
void evaluateChoice(int);

void main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    createList(n);
    
    menu();
}

void menu() {
    int choice;
    for (;;) {
        system("cls");
        printf("\n-----------------------M E N U---------------------------\n\n");
        printf("1. INSERT node at BEGINNING\n");
        printf("2. INSERT node at END\n");
        printf("3. DELETE node at BEGINNING\n");
        printf("4. DELETE node at END\n");
        printf("5. DISPLAY list in FORWARD direction\n");
        printf("6. DISPLAY list in BACKWARD direction\n");
        printf("7. Exit\n\n");

        printf("Enter choice (1-7): ");
        scanf("%d", &choice);

        evaluateChoice(choice);
        printf("\n");
        system("pause");
    }
}

void evaluateChoice(int n) {
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));

    switch(n) {
        case 1:
            system("cls");
            printf("Enter node to insert at beginning: ");
            scanf("%d", &new->data);

            insertBeg(new);
            break;

        case 2:
            system("cls");
            printf("Enter node to insert at beginning: ");
            scanf("%d", &new->data);

            insertEnd(new);
            break;

        case 3:
            system("cls");
            deleteBeg();
            break;

        case 4:
            system("cls");
            deleteEnd();
            break;

        case 5:
            system("cls");
            displayList();
            break;

        case 6:
            system("cls");
            traverseRev();
            break;

        case 7:
            exit(0);

        default:
            system("cls");
            printf("Invalid choice entered!");
    }
}

void createList(int n) {
    struct node *temp, *curr;

    for (int i = 0; i < n; i++) {
        curr = (struct node *)malloc(sizeof(struct node));
        printf("Enter node #%d: ", (i + 1));
        scanf("%d", &curr->data);

        if (i == 0) {
            head = temp = curr;
            head->prev = NULL;
        }
        else {
            temp->next = curr;
            curr->prev = temp;
            temp = curr;

        }
    }
    temp->next = NULL;
}

void displayList() {
    struct node *temp;

    temp = head;

    if (head == NULL) {
        printf("No nodes to print!\n");
        return;
    }
    else {
        printf("\n");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void insertBeg(struct node *new) {
    new->prev = NULL;

    if (head == NULL) {
        new = head;
        return;
    }
    else {
        head->prev = new;
        new->next = head;

        head = new;
    }
}

void insertEnd(struct node *new) {
    new->next = NULL;
    struct node *temp;
    temp = head;

    if (head == NULL) {
        new = head;
        return;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
        new->prev = temp;
    }
}

void deleteBeg() {
    struct node *temp;
    temp = head;

    if (head == NULL) {
        printf("No nodes present to delete!");
        return;
    }
    else {
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
    }
}

void deleteEnd() {
    struct node *curr, *nextNode;
    curr = nextNode = head;

    if (head == NULL) {
        printf("No nodes to delete!");
        return;
    }
    else {
        while (nextNode->next != NULL) {
            curr = nextNode;
            nextNode = nextNode->next;
        }
        if (nextNode == NULL) {
            head = NULL;
        }
        else {
            nextNode->prev = NULL;
            curr->next = NULL;
        }
    }
}

// Traversing in forward (single direction is the same code)
void traverseRev() {
    struct node *temp;
    temp = head;

    if (head == NULL) {
        printf("No nodes");
        return;
    }
    else {
        printf("\n");
        while (temp->next != NULL) {
            temp = temp->next;
        }

        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->prev;
        }
    }
}