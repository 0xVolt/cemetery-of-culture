/* Code by Desh Iyer

* Program to sum the elements of an array using recursion */

#include <stdio.h>

int sumArray(int *, int);

int main() {
    int N, i;
    int *array;

    printf("Enter number of elements: ");
    scanf("%d", &N);

    printf("\nEnter array elements: ");
    for (i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    int sum = sumArray(array, N);

    printf("\nSum of the elements of the array = %d", sum);

    return 0;
}

int sumArray(int *array, int N) {
    if (N <= 0) {
        return 0;
    }
    else {
        return (sumArray(array, N - 1) + array[N - 1]);
    }
}