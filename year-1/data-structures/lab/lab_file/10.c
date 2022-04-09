#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int queue[MAX];
int front = -1;
int rear = -1;

void en_queue(int n)
{
    if ((front == 0 && rear == MAX - 1) || (front > 0 && rear == front - 1))
    {
        printf("\n Overflow Condition....");
    }
    else if (rear == -1)
    {
        rear = front = 0;
        queue[rear] = n;
    }
    else
    {
        rear = (rear + 1) % MAX;
        queue[rear] = n;
    }
}

void de_queue()
{
    if (rear == -1)
    {
        printf("\n Underflow condition....");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
    printf("\n Deleted the element\n");
}

void display()
{
    int i = front;
    if (rear == -1)
        printf("\n Queue is empty.....Underflow");
    else
    {
        printf("\nElements in a Queue are :");
        while (i != rear)
        {
            printf(" %d", queue[i]);
            i = (i + 1) % MAX;
        }
    }
}

int main()
{
    int choice, n;
    while (1)
    {
        printf("\n*****MENU*****");
        printf("\n1: Insert an element");
        printf("\n2: Delete an element");
        printf("\n3: Display the element");
        printf("\n4.Exit");
        printf("\nEnter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element which is to be inserted:");
            scanf("%d", &n);
            en_queue(n);
            break;
        case 2:
            de_queue();
            break;
        case 3:
            display();
            break;
        default:
            exit(1);
        }
    }
    return 0;
}
