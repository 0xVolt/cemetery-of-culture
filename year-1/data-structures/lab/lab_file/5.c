#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *temp;

void insertion_beg(struct node *);
void insertion_end(struct node *);
void deletion_beg();
void deletion_end();
void traverse();

int main()
{
    int choice;
    struct node *new1;

    while (1)
    {
        printf("\n Enter the choice:");
        printf("\n 1.Insertion at the beginning. \n 2.Insertion at the end.");
        printf("\n 3.Deletion at the beginning. \n 4.Deletion at the end.");
        printf("\n 5.Traversing in the list. \n 6.Quit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            new1 = (struct node *)malloc(sizeof(struct node));
            printf("Enter the data\n");
            scanf("%d", &new1->data);
            new1->next = NULL;
            insertion_beg(new1);
            break;
        case 2:
            new1 = (struct node *)malloc(sizeof(struct node));
            printf("Enter the data\n");
            scanf("%d", &new1->data);
            new1->next = NULL;
            insertion_end(new1);
            break;
        case 3:
            deletion_beg();
            break;
        case 4:
            deletion_end();
            break;
        case 5:
            traverse();
            break;
        default:
            exit(1);
        }
    }
}
void insertion_beg(struct node *new1)
{
    if (head == NULL)
        head = new1;
    else
    {
        new1->next = head;
        head = new1;
    }
}

void insertion_end(struct node *new1)
{
    temp = head;
    if (head == NULL)
        head = new1;
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new1;
    }
}

void deletion_beg()
{
    if (head == NULL)
        printf("Nothing to Delete in here!!!!\n");
    else
        head = head->next;
}

void deletion_end()
{
    struct node *temp = head;
    struct node *temp1 = head;
    if (head == NULL)
        printf("Nothing to Delete in here!!!!\n");
    else
    {
        while (temp1->next != NULL)
        {
            temp = temp1;
            temp1 = temp1->next;
        }
        if (temp1 == head)
            head = NULL;
        else
            temp->next = NULL;
    }
}

void traverse()
{
    struct node *temp = head;
    if (head == NULL)
        printf("Nothing to traverse\n");
    printf("\n Data in the list:");
    while (temp != NULL)
    {
        printf("\n%d ", temp->data);
        temp = temp->next;
    }
}
