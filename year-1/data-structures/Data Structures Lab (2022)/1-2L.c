/*
Akshit Gandotra
Question 2 (Lab)
Program to Create an Array 'a1' with 'n' elements. Insert an element in ith position and delete an element in jth
position of the Array.
*/

#include <stdio.h>

int main()
{
    int n;  // size of array
    printf("Enter the Size of Array \n");
    scanf("%d", &n);  // user input
    int a1[n];
    input(a1, n);
    display(a1, n);
    DeleteIndex(a1, n);
    AddIndex(a1, n);
    display(a1, n);
}


void input(int *A, int n)   // function to input elements
{
    for(int i = 0; i < n; i++)  
    {
        printf("Enter a Number:\n");  
        scanf("%d", &A[i]);  // user input
    }
}

void AddIndex(int *A, int n)  // function to add elemts
{
    int i, num;
    printf("Enter the position to add the index and the Number to add:\n");  
    scanf("%d %d", &i, &num );  // user input
    for(int k = n-1; k > i; k--)
    {
        A[k] = A[k-1];
    }
    A[i] = num;
}

void DeleteIndex(int *A , int n)  // function to delete the element of index
{
    int j;
    printf("Enter the position to delete the index:\n");  // accept the position to delete
    scanf("%d" , &j);
    for(int i = j; i < n-1; i++)
    {
        A[i] = A[i+1];
    }
}

void display ( int *A , int n)
{ 
    printf("The Array Elements are: \n");
    for(int i = 0; i < n; i++)  // display array
    {
        printf("%d\n", A[i]);
    }
}