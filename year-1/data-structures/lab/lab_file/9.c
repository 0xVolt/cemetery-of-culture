#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 10

void en_queue(int n);
void de_queue();
void display();
int queue[MAX];
int rear = -1;
int front = -1;

int main()
{
    int n, choice;
    while (1)
    {
        printf("\nM E N U\n");
        printf("1. Insert element into the Queue\n2. Delete element from the Queue\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Insert the element in queue : ");
            scanf("%d", &n);
            en_queue(n);
            break;
        case 2:
            de_queue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("\nInvalid option selected! Please try again!!!\n");
        }
    }
}

void en_queue(int n)
{

    if (rear == MAX - 1)
    {
        printf("Queue Overflow \n");
    }
    else if (rear == -1)
    {
        rear = front = 0;
        queue[rear] = n;
    }
    else
    {
        rear = rear + 1;
        queue[rear] = n;
    }
}

void de_queue()
{
    if (rear == -1)
        printf("\nQueue is Empty!!!\n");
    else if (front == rear)
    {
        rear = front = -1;
    }
    else
    {
        front = front + 1;
    }
    printf("\n Element Deleted*****\n");
}

void display()
{
    int i = front;
    if (front == -1)
        printf("\nQueue is Empty!!!\n");
    else
    {
        printf("\n Elements in the Queue are:");
        while (i <= rear)
        {
            printf(" %d", queue[i]);
            i++;
        }
    }
}
