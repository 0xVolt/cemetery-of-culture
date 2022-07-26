// Code by Desh Iyer

// PROBLEM STATEMENT
// Define two arrays, store and traverse them using pointers

// Include Libraries
#include <stdlib.h>
#include <stdio.h>

// Function prototypes
void enterArray(int *, int);
void printArray(int *, int);

// Start of main()
int main() {
    int *arr1, *arr2;
    int n1, n2;

    printf("Enter the size of Array 1: ");
    scanf("%d", &n1);

    printf("Enter the size of Array 2: ");
    scanf("%d", &n2);

    arr1 = (int *) malloc(n1 * sizeof(int));
    arr2 = (int *) malloc(n2 * sizeof(int));


    printf("\nEnter Array 1:\n");
    enterArray(arr1, n1);
    
    printf("Displaying Array 1:\n");
    printArray(arr1, n1);

    printf("\n\nEnter Array 2:\n");
    enterArray(arr2, n2);
    printf("Displaying Array 2:\n");
    printArray(arr2, n2);

    free(arr1);
    free(arr2);
} // End of main()

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