/*
Akshit Gandotra
Question 4 (Practice)
Find the smallest and the largest element in the Array.
*/
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the Size of Array \n");
    scanf("%d", &n);
    int Arr[n];  // array initialization
    input((int *)Arr, n);  // function call to input data in the Array
    printf("The Array is :\n");    
    display(n, Arr);  // function call to display data in the Array
    find(n, Arr);  // function call to find the smallest and the largest Number in the Array
}


void input(int *A, int n)  // function to input data in the Array
{
    for(int i = 0; i < n; i++)
    {
        printf("Enter a Number\n");
        scanf("%d", &A[i]);  // user input
    } 
}

void display(int n, int A[n])  // function to display data in the Array
{
    for(int i = 0; i < n; i++)
    {
        printf("%d \t", A[i]);
    }
    printf("\n");
}

void find(int n, int A[n])  // function to find the smallest and the largest Number in the Array
{
    int max = A[0];
    int min = A[0];
    for(int i = 0; i < n; i++)
    {
        if (max < A[i])
        max = A[i];
        if(min > A[i])
        min = A[i];
    }
    printf("Largest Number in the Array is %d \nSmallest Number in the Array is %d", max, min);
}