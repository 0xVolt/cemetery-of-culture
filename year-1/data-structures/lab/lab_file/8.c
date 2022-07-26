#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void push();
void pop();
void display();
int stack[MAX];
int top = -1; //No element initially
int main()
{
    int choice, n;
    while (1) //Loop for choice, infinite run
    {
        printf("\n Enter the choice");
        printf("\n 1.Push \n 2.Pop \n 3.Display \n 4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("\n Wrong choice");
        }
    }
}

void push()
{
    int n;
    if (top >= MAX - 1)
        printf("\n Stack Overflow");
    else
    {
        top = top + 1;
        printf("\n Enter the number to push: ");
        scanf("%d", &n);
        stack[top] = n;
    }
}
void pop()
{
    if (top == -1)
        printf("\n Stack is underflow");
    else
        top = top - 1;
}

void display()
{
    int i = top;
    if (top == -1)
        printf("\n Nothing to diplay");
    else
    {
        while (i >= 0)
        {
            printf("\n %d", stack[i]);
            i--;
        }
    }
}
