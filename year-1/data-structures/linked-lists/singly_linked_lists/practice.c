#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void createList(int);
void displayList();
void insertBeg(struct node *);
void insertEnd(struct node *);
void deleteBeg();
void deleteEnd();

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    createList(n);
    displayList();

    deleteEnd();
    displayList();

    return 0;
}

void createList(int n) {
    struct node *temp, *curr;

    for (int i = 0; i < n; i++) {
        curr = (struct node *)malloc(sizeof(struct node));
        printf("Enter the node data #%d: ", (i + 1));
        scanf("%d", &curr->data);

        if (i == 0) {
            head = temp = curr;
        }
        else {
            temp->next = curr;
            temp = curr;
        }

        temp->next = NULL;
    }
}

void displayList() {
    struct node *temp;

    temp = head;

    if (head == NULL) {
        printf("No elements to print!");
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
    if (head == NULL) {
        head = new;
    }
    else {
        new->next = head;
        head = new;
    }
}

void insertEnd(struct node *new) {
    struct node *temp;
    temp = head;
    new->next = NULL;

    if (head == NULL) {
        head = new;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = new;
    }
}

void deleteBeg() {
    struct node *temp;

    temp = head;

    if (head == NULL) {
        printf("No nodes to delete!");
        return;
    }
    else {
        head = head->next;
        temp->next = NULL;
    }
}

void deleteEnd() {
    struct node *currNode, *nextNode;
    currNode = head;
    nextNode = head;

    if (head == NULL) {
        printf("No nodes to delete!");
        return;
    }
    else {
        while (nextNode->next != NULL) {
            currNode = nextNode;
            nextNode = nextNode->next; 
        }

        if (nextNode == head) {
            head = NULL;
        }
        else {
            currNode->next = NULL;
        }
    }
}