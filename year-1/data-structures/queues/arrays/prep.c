#include <stdio.h>

#define MAX 3

int queue[10];
int front = -1;
int rear = -1;

void enqueue(int);
void dequeue();
void display();
void retFront();
void isEmpty();

int main() {
    int data;
    printf("Enter data to insert into queue: ");
    scanf("%d", &data);
    enqueue(data);

    printf("Enter data to insert into queue: ");
    scanf("%d", &data);
    enqueue(data);

    printf("Enter data to insert into queue: ");
    scanf("%d", &data);
    enqueue(data);

    display();

    dequeue();

    display();
}

void enqueue(int data) {
    if (rear >= MAX - 1) {
        printf("Queue full!");
        return;
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = data;
    }
    else {
        rear ++;
        queue[rear] = data;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue empty!");
        return;
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front ++;
    }
}

void display() {
    if (front == -1) {
        printf("No elements in the queue");
        return;
    } else {
        for (int i = front; i <= rear; i ++) {
            printf("%d ", queue[i]);
        }
    }
}