/*
Akshit Gandotra
Question 5 (Practice)
Create an array ‘a1’ with ‘n’ elements. 
(i)	Copy all the elements of ‘a1’ into another array ‘a2’ using pointer. Display the content of both the array using pointer.
(ii) Merge the content of ‘a1’ and ‘a2’ into the new array ‘a3’.
*/

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the Size of array \n");
    scanf("%d", &n);
    int a1[n];  // array initialization
    int a2[n];  // array initialization
    int a3[n];  // array initialization
    input((int *)a1, n);  // function call to input data in the array
    printf("Array1 is :\n");    
    display(n, a1);  // function call to display data in the array
    copy((int *)a2, n, a1);  // function call to copy the datas of the array
    printf("Array2 is :\n");    
    display(n, a2);  // function call to display data in the array
    merge((int *)a3, n, a1, a2);  // function call to merge the datas of the array
    printf("Array3 is :\n");    
    display(n, a3);  // function call to display data in the array
}


void input(int *A, int n)  // function to input data in the array
{
    for(int i = 0; i < n; i++)
    {
        printf("Enter a Number\n");
        scanf("%d", &A[i]);  // user input
    } 
}

void display(int n, int A[n])  // function to display data in the array
{
    for(int i = 0; i < n; i++)
    {
        printf("%d \t", A[i]);
    }
    printf("\n");
}

void copy(int *A2, int n, int A1[n])  // function to copy the datas of the array
{
    for(int i = 0; i < n; i++)
    {
        A2[i] = A1[i];
    }
}

void merge(int *A3, int n, int A1[n], int A2[n])  // function to merge the datas of the array
{
    for ( int i = 0; i < n; i++)
    {
        A3[i] = A1[i] + A2[i];
    }
}