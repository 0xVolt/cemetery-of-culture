/* Code by Desh Iyer */
/* Menu driven program to demostrate stacks as arrays */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int stack[MAX];
int top = -1;

/* Function delcarations */
void push(int);
void pop();
void display();
bool checkEmpty();
bool checkFull();
void menu();

/* Driver function */
int main() {
    menu();

    return 0;
}

void menu() {
    int choice;
    int data;
    for (;;) {
        system("cls");
        printf("\nM E N U\n\n");
        printf("1. Push an element to the stack\n");
        printf("2. Pop an element from the stack\n");
        printf("3. Display all elements of the stack\n");
        printf("4. Check if the stack is empty\n");
        printf("5. Check if the stack is full\n");
        printf("6. Exit\n\n");

        printf("Enter a choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("cls");
                printf("Enter the data to push to the stack: ");
                scanf("%d", &data);
                push(data);
                printf("Data pushed to the stack!\n");
                system("pause");
                
                break;

            case 2:
                system("cls");
                pop();
                system("pause");

                break;

            case 3:
                system("cls");
                printf("Displaying stack:\n");
                display();
                printf("\n");
                system("pause");

                break;

            case 4:
                system("cls");
                if (checkEmpty()) {
                    printf("Stack is empty!\n\n");
                } else {
                    printf("Stack is not empty!\n\n");
                }
                system("pause");

                break;

            case 5:
                system("cls");
                if (checkFull()) {
                    printf("Stack is full!");
                } else {
                    printf("Stack is not full!");
                }
                system("pause");

                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice entered!");
                system("pause");
        }
    }
}

void push(int data) {
    if (top >= MAX - 1) {
        printf("Stack overflow!");
        return;
    } else {
        top++;
        stack[top] = data;
    }
}

void display() {
    int temp;
    temp = top;
    if (top == -1) {
        printf("Stack empty!");
    } else {
        while (temp != -1) {
            printf("\t%d\n", stack[temp]);
            temp--;
        }
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow!");
        return;
    } else {
        printf("Popping top element!\n");
        printf("%d", stack[top]);
        top--;
    }
}

bool checkEmpty() {
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

bool checkFull() {
    if (top >= MAX - 1) {
        return true;
    } else {
        return false;
    }
}