//Linear search
#include <stdio.h>

int Linearsearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
int main(void)
{
    int i, j, n, x, arr[10];
    printf("\n Enter the size of array(max 10):");
    scanf("%d", &n);
    printf("\n Enter the array:\n");
    for (i = 0; i < n; i++)
        scanf("\n %d", &arr[i]);
    printf("\n Enter the element to search:");
    scanf("%d", &x);

    // Function call
    int result = Linearsearch(arr, n, x);
    if (result == -1)
        printf(" Element is not present in array");
    else
        printf(" Element is present at index: %d", result);
    return 0;
}
