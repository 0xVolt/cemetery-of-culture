#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(struct Node *);
void pop();
void checkTop();
void isEmpty();
void display();

int main() {
    struct Node *new;
    for (int i = 0; i < 2; i ++) {
        new = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter node: ");
        scanf("%d", &new->data);
        push(new);
    }

    display();
    pop();
    display();

    free(new);

    return 0;
}

void push(struct Node *new) {
    new->next = top;
    top = new;
}

void pop() {
    if (top == NULL) {
        printf("Stack Overflow!");
        return;
    } else {
        top = top->next;
    }
}

void display() {
    struct Node *temp;
    temp = top;

    if (top == NULL) {
        printf("No nodes in stack!");
        return;
    } else {
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}