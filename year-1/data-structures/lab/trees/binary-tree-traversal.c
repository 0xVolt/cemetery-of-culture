#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
 
struct node *newNode(int data) {
    struct node* node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

void inorder(struct node *root) {
    if (root == NULL) return; 
    inorder(root->left);
    printf("%d \n", root->data);
    inorder(root->right);
}

void preorder(struct node *root) {
    if (root == NULL) return; 
    printf("%d \n", root->data);
	preorder(root->left);
    preorder(root->right);
}


void postorder(struct node *root) {
    if (root == NULL) return; 
    postorder(root->left);
    postorder(root->right);
    printf("%d \n", root->data);
}

 
int main() {
    struct node *root = NULL;

	root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    
    printf("in-order traversal\n");
    inorder(root);
    printf("pre-order traversal\n");
    preorder(root);
    printf("post-order traversal\n");
    postorder(root);

    getchar();
    return 0;
}