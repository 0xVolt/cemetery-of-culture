#include <stdio.h>
#include <stdlib.h>

typedef struct BINARY_SEARCH_TREE {
    int data;
    struct BINARY_SEARCH_TREE *left;
    struct BINARY_SEARCH_TREE *right;
}BST;

BST root_node = NULL;

BST *create_node(int);
BST *insert_node(int);

int main() {
    

    return 0;
}

BST *create_node(int value) {
    BST *new_node;
    new_node = (BST *)malloc(sizeof(BST));

    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

BST *insert_node(int value) {
    if (root_node == NULL) {
        return create_node(value);
    } 
    else if (value < root_node->data) {
        root_node->left = insert_node(new_node);
    }
    else if (value > root_node->data) {
        root_node->right = insert_node(value);
    }
}

BST *search_node(int key) {
    if (root_node->data == key || root_node == NULL) {
        return root_node;
    }
    else {
        if (root_node->data < key) {
            return search(root_node->right, key);
        }
        else {
            return search(root_node->left, key);
        }
    }
}