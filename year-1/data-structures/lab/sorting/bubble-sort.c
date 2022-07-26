#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sort(int *, int, char);
void swap(int *, int *);

int main() {
    int array[25], sorted_array[25];
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    char choice;
    fflush(stdin);
    printf("Sort in ascending or descending order? (a / d): ");
    scanf("%c", &choice);
    choice = tolower(choice);

    sort(array, n, choice);

    printf("Printing array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}

void swap(int *a, int *b) {
    int temp;

    temp = *b;
    *b = *a;
    *a = temp;
}

void sort(int *arr, int n, char choice) {
    int temp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (choice == 'a') {
                if (arr[j] > arr[j + 1]) {
                    swap(&arr[j], &arr[j + 1]);
                }
            } else if (choice == 'd') {
                if (arr[j] < arr[j + 1]) {
                    swap(&arr[j], &arr[j + 1]);
                }
            }
        }
    }
}