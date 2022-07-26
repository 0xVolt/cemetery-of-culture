#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
}Node;

Node *rootNode = NULL;

void createTree(int);
void traverseTree();
void preorderTrav();
void inorderTrav();
void postorderTrav();

int main() {
    int n; /* Number of nodes */

    printf("How many nodes?: ");
    scanf("%d", &n);

    printf("Creating a complete binary tree having %d nodes...\n", n);

    createTree(n);
}

void createTree(int n) {
    Node *tempNode, *newNode;

    tempNode = newNode = rootNode;

    for (int i = 0; i < n; i++) {
        newNode = (Node *)malloc(sizeof(Node));

        printf("Enter node #%d: ", (i + 1));
        scanf("%d", &newNode->data);
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;

        if (i == 0) {
            tempNode = newNode = rootNode;
        } else {
            if ((i + 1) % 2 == 0) {
                tempNode->leftChild = newNode;
            } else {
                tempNode->rightChild = newNode;
            }
        }

        if (tempNode->leftChild != NULL && tempNode->rightChild != NULL) {
            tempNode = tempNode->leftChild;
        }

        tempNode->leftChild = NULL;
        tempNode->rightChild = NULL;
    }
}

void traverseTree() {
    int option;

    printf(
        "1. Pre-order traversal\n"
        "2. In-order traversal\n"
        "3. Post-order traversal\n"
        "4. Exit\n\n"

        "Enter choice: "
    );
    scanf("%d", &option);

    switch (option) {
        case 1:
            preorderTrav();
            break;
        
        case 2:
            inorderTrav();
            break;

        case 3:
            postorderTrav();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice!");
    }
}

void preorderTrav() {
    if (rootNode == NULL) 
        return;
    
    printf("%d \n", rootNode->data);
    preorderTrav(rootNode->leftChild);
    preorderTrav(rootNode->rightChild);
}

void inorderTrav() {
    if (rootNode == NULL) 
        return;
    
    inorderTrav(rootNode->leftChild);
    printf("%d \n", rootNode->data);
    inorderTrav(rootNode->rightChild);
}

void postorderTrav() {
    if (rootNode == NULL) 
        return;
    
    postorderTrav(rootNode->leftChild);
    postorderTrav(rootNode->rightChild);
    printf("%d \n", rootNode->data);
}