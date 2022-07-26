// Code by Desh Iyer

// PROBLEM STATEMENT
// Find the element inside the array using pointers

// Include Libraries
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Function prototypes
int findIndex(int *, int, int);
void enterArray(int *, int);
void printArray(int *, int);

// Start of main()
int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *) malloc(n * sizeof(int));

    printf("Enter the array:\n");
    enterArray(arr, n);

    int element;
    printf("Enter the element to search the array for: ");
    scanf("%d", &element);

    int index = findIndex(arr, n, element);

    if (index == -1) {
        printf("Element %d is not present in the array");
    } else {
        printf("The element %d was found at index %d", element, index);
    }

    free(arr);
} // End of main()

int findIndex(int *array, int size, int elt) {
    bool flag = false;
    
    int i = 0;
    while (!flag && i < size) {
        if (array[i] == elt) {
            flag = true;
            return i;
            break;
        } else {
            ++i;
        }
    }

    if (!flag) {
        return -1;
    }
}

void enterArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
}

void printArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}