#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *AddToEmpty(int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
}

struct node *AddAtEnd(struct node *tail, int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    newnode->next = tail->next;
    tail->next = newnode;
    tail = tail->next;
}

struct node *CreateList(struct node *tail)
{
    int i, n, data;
    printf("Enter number of nodes to be added \n");
    scanf("%d", &n);
    if (n == 0)
    {
        return tail;
    }
    printf("Enter the element 1 :");
    scanf("%d", &data);
    tail = AddToEmpty(data);
    for (i = 1; i < n; i++)
    {
        printf("Enter the element %d :", (i + 1));
        scanf("%d", &data);
        tail = AddAtEnd(tail, data);
    }
    return tail;
}
void print(struct node *tail)
{
    if (tail == NULL)
    {
        printf("No nodes to print\n");
    }
    else
    {
        struct node *prnt = tail->next;
        do
        {
            printf("%d \n", prnt->data);
            prnt = prnt->next;

        } while (prnt != tail->next);
    }
    printf("\n");
}

int main()
{
    struct node *tail = NULL;
    tail = CreateList(tail);
    print(tail);
    return 0;
}