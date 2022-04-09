#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();
void menu();

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

/* Driver function */
int main() {
    menu();

    return 0;
}

void menu() {
    int choice;
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    for (;;) {
        system("cls");
        printf("\nM E N U\n\n");
        printf("1. Push an element to the stack\n");
        printf("2. Pop an element from the stack\n");
        printf("3. Display all elements of the stack\n");
        printf("4. Exit\n\n");

        printf("Enter a choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("cls");
                push();
                system("pause");
                
                break;

            case 2:
                system("cls");
                pop();
                printf("Element popped!\n");
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
                exit(0);

            default:
                printf("Invalid choice entered!");
                system("pause");
        }
    }
}

void push() {  
    int val;  
    struct node *ptr = (struct node*)malloc(sizeof(struct node));   
    if (ptr == NULL) {  
        printf("Unable to push the element");   
    } else {  
        printf("Enter the value to push to the stack: ");  
        scanf("%d", &val);  
        if (top == NULL) {         
            ptr->data = val;  
            ptr->next = NULL;  
            top = ptr;
        } else {  
            ptr->data = val;  
            ptr->next = top;  
            top = ptr;     
        }  
        printf("Item pushed\n\n");
    }  
}

void pop() {
    if (top == NULL) {
        printf("Stack underflow!");
        return;
    } else {
        top = top->next;
    }
}

void display() {  
    int i;  
    struct node *temp;  
    temp = top;  
    if(temp == NULL) {  
        printf("Stack is empty\n");  
    } else {  
        printf("Printing Stack elements \n");  
        while(temp != NULL) {  
            printf("%d\n",temp->data);  
            temp = temp->next;  
        }  
    }  
}