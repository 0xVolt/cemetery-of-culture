//Binary search
#include <stdio.h>
 
int BinarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return BinarySearch(arr, l, mid - 1, x);
        return BinarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
 
int main(void)
{
    int i,j,n,x,arr[10];
    printf("\n Enter the size of array(max 10):");
    scanf("%d", &n);
    printf("\n Enter the array:\n");
    for(i=0;i<n;i++)
    scanf("\n %d", &arr[i]);
    printf("\n Enter the element to search:");
    scanf("%d", &x);
   
    // Function call
    int result = BinarySearch(arr, 0, n-1, x);
    if(result == -1)
    printf(" Element is not present in array");
    else
    printf(" Element is present at index: %d", result);
    return 0;
}
