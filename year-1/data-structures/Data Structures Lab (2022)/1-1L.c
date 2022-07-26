/*
Akshit Gandotra
Question 1 (Lab)
Program to Calculate the sum of Array Elements
*/

#include <stdio.h>

int main()
{
    int n; // size of array
    printf("Enter the Size of Array:\n");
    scanf("%d", &n); // value assignment
    int Arr[n];
    input(Arr, n); // function call
    int sumArray = sum(Arr, n, 0); // function call
    printf("The sum of Array Elements = %d", sumArray); // print sum
}


void input(int *A, int n) // function to input elements
{
    for(int i = 0; i < n; i++)  
    {
        printf("Enter a Number:\n");  
        scanf("%d", &A[i]);  // value assignment
    }
}
int sum(int A[], int n, int m) // function to calculate sum of array
{
    if(n == m) // recursion base condition
    return 0;                         
    return A[m] + sum(A, n, m+1); // recursive function
}