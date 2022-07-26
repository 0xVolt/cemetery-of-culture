/* Code by Desh Iyer
* Menu driven program to implement Queue using Array */

#include <stdio.h>
#include <stdlib.h> /* For exit() */
 
#define MAX 50

/* Function declarations */
void enqueue();
void dequeue();
void display();

int queue_array[MAX];
int rear = - 1;
int front = - 1;

/* Start of main() function */
int main() {
    int choice;
    while (1) {
        system("cls");
        printf("---------------M E N U----------------\n\n");
        printf("1. Enqueue element to queue \n");
        printf("2. Dequeue element from queue \n");
        printf("3. Display all elements of queue \n");
        printf("4. Exit \n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong choice \n");
        }

        printf("\n");
        system("pause");
    }
} /* End of main() */

/* Function to enqueue an element to the Queue */
void enqueue()
{
    int element;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        /*If queue is initially empty */
        front = 0;
        printf("Enter the element to enqueue: ");
        scanf("%d", &element);
        rear = rear + 1;
        queue_array[rear] = element;
    }
} /* End of enqueue() */

/* Function to dequeue an element from the Queue */
void dequeue()
{
    if (front == - 1 || front > rear) {
        printf("Queue Underflow \n");
        return ;
    } else {
        printf("Element dequeued is : %d\n", queue_array[front]);
        front = front + 1;
    }
} /* End of dequeue() */

/* Function to traverse the Queue and display all the elements in the Queue */
void display() {
    int i;
    if (front == - 1)
        printf("Queue is empty\n");
    else {
        printf("Printing queue: \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
} /* End of display() */