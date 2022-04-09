#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *temp;

void ins_beg(struct node *);
void ins_end(struct node *);
void del_beg();
void del_end();
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
            ins_beg(new1);
            break;
        case 2:
            new1 = (struct node *)malloc(sizeof(struct node));
            printf("Enter the data\n");
            scanf("%d", &new1->data);
            new1->next = NULL;
            ins_end(new1);
            break;
        case 3:
            del_beg();
            break;
        case 4:
            del_end();
            break;
        case 5:
            traverse();
            break;
        default:
            exit(1);
        }
    }
}

void ins_beg(struct node *new1)
{
    struct node *temp = head;
    if (head == NULL)
    {
        head = new1;
        head->next = head;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        new1->next = head;
        temp->next = new1;
        head = new1;
    }
}

void ins_end(struct node *new1)
{
    struct node *temp = head;
    if (head == NULL)
    {
        head = new1;
        head->next = head;
    }
    else
    {
        while (temp->next != head)
            temp = temp->next;
    }
    temp->next = new1;
    new1->next = head;
}

void del_beg()
{
    struct node *temp = head;
    if (head == NULL)
        printf("\n No elements to Delete*****");
    else if (head->next == head)
    {
        printf("Item deleted is =%d\n", head->data);
        head = NULL;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        printf("\n Item deleted from the list is =%d\n", head->data);
        head = head->next;
        temp->next = head;
    }
}

void del_end()
{
    struct node *temp;
    struct node *temp1;
    if (head == NULL)
    {
        printf("\n Nothing to delete in here****");
    }
    else if (head->next == head)
    {
        head = NULL;
        printf("\n Element Deleted");
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = temp->next;
        printf("\n Element deleted");
    }
}

void traverse()
{
    struct node *temp = head;
    if (head == NULL)
        printf("\n No elements in the list");
    else
    {
        do
        {
            printf("\t%d\n", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}
