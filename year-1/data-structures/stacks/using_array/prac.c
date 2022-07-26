#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3

int stack[MAX];
int top = -1;

void push(int); // Push an element to the stack
void pop(); // Pop an element from the stack
void checkTop(); // Check which element is at Top posn
void isEmpty(); // Check if the stack is empty
void display();

int main() {
    int n;

    printf("Enter element to push to the stack: ");
    scanf("%d", &n);
    push(n);

    display();

    pop();

    pop();

    return 0;
}

void push(int n) {
    if (top >= MAX - 1) {
        printf("Stack overflow!");
        return;
    } else {
        top ++;
        stack[top] = n;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow!");
        return;
    } else {
        top --;
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("No elements in the stack!\n");
        return;
    } else {
        printf("Printing stack:\n");
        for (i = top; i >= 0; i --) {
            printf("%d\n", stack[i]);
        }
    }
}

void checkTop() {
    if (top == -1) {
        printf("No elements present in stack!");
        return;
    } else {
        printf("Top is at position %d and the element at top is %d\n", top + 1, stack[top]);
    }
}

void isEmpty() {
    if (top == -1) {
        printf("Stack is empty!");
    } else {
        printf("Stack is not empty!");
    }
}