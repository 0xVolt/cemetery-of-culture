#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *next;
};

struct NODE *head = NULL;

struct NODE *accept_node(struct NODE *);
void create_list(int);
void insert_node_beginning(struct NODE *);
void insert_node_end(struct NODE *);

/* Driver function */
int main () {
    struct NODE *new_node;
    new_node = accept_node(new_node);
    

}

struct NODE *accept_node(struct NODE *new_node) {
    new_node = (struct NODE *)malloc(sizeof(struct NODE));

    printf("Enter node's data: ");
    scanf("%d", &new_node->data);

    return new_node;
}

void insert_node_beginning(struct NODE *new_node) {
    
}