#include <stdio.h>

int main() {
    int arr[25], i, n, max, min;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("\nEnter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max = min = arr[0];
    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        else if (arr[i] < min) {
            min = arr[i];
        } 
    }   

    printf("\nGiven array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nMaximum elt = %d\nMinimum elt = %d", max, min);
}