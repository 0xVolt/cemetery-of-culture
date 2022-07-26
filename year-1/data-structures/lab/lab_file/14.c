#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int data;
    struct BST *root;
    struct BST *left;
    struct BST *right;
    struct BST *node;
    struct BST *value;
};

//Function for creation of a node for the binary tree
struct BST *new1(int value)
{
    struct BST *new1 = (struct BST *)malloc(sizeof(struct BST));
    new1->data = value;
    new1->left = NULL;
    new1->right = NULL;
    return new1;
}

//Function for Insertion in the binary tree
struct BST *insert(struct BST *root, int value)
{
    if (root == NULL)
        root = new1(value);
    else if (root->data > value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

//Functions for Getting the order of Binary tree
void inorder(struct BST *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d", root->data);
        inorder(root->right);
    }
}

//Function for preorder
void preorder(struct BST *root)
{
    if (root != NULL)
    {
        printf(" %d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

//Function for postorder
void postorder(struct BST *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d", root->data);
    }
}

int main()
{
    int n, r, s, key, del, sea;
    struct BST *root;
    printf("\n Enter the root of the binary tree:");
    scanf("%d", &r);
    root = insert(NULL, r);
    printf("\n Enter the number of nodes you want to add:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\n Enter the value of nodes:");
        scanf("%d", &s);
        root = insert(root, s);
    }

    int choice;
    while (1)
    {
        printf("\n Enter the choice:");
        printf("\n 1.Insertion in the binary tree.");
        printf("\n 2.Preorder of binary tree. \n 3.Postorder of binary tree.");
        printf("\n 4.Inorder of the binary tree. \n 5.Exit");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter the value to add:");
            scanf("%d", &s);
            insert(root, s);
            break;

        case 2:
            printf("\n Preorder of the binary tree is:");
            preorder(root);
            break;

        case 3:
            printf("\n Postorder of the binary tree is:");
            postorder(root);
            break;

        case 4:
            printf("\n Inorder of the binary tree is:");
            inorder(root);
            break;

        default:
            exit(1);
        }
    }
}
