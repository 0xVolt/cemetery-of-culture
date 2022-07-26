#include <stdio.h>

void pa(int *, int);
void ins(int *, int);
void swap(int *, int *);

int main() {
    int n;
    int a[25];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements of the unsorted aay:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Unsorted:\n");
    pa(a, n);

    ins(a, n);

    printf("\nSorted:\n");
    pa(a, n);

    return 0;
}

void pa(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void swap(int *a, int *b) {
    int temp;

    temp = *b;
    *b = *a;
    *a = temp;
}

void ins(int *a, int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}