/*
Akshit Gandotra
Question 2 (Practice)
Create an integer array of user defined size n1 with dynamic memory allocation. Store data after reading from keyboard. Expand the size of array with n2. Read new values (n2 values from keyboard). Print state of array with all (n1+n2) values.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *Array1;
    int *Array2;
    int n1;
    printf("Enter the size of the Array:\n");
    scanf("%d", &n1);
    Array1 = (int *)malloc(sizeof(int)*n1);  // dynamic allocation using malloc
    for(int i = 0; i < n1; i++)               
    {
        printf("Enter a Number:\n");
        scanf("%d", &Array1[i]);  // user input
    }
    
    printf("The Array is:\n");
    display(Array1, n1);
    int n2;
    
    printf("Enter the increased size of the Array:\n");
    scanf("%d", &n2);
    Array2 = (int *)realloc(Array1, n2); 
    
    for(int i = n1; i < n2; i++)
    {
        printf("Enter a Number:\n");
        scanf("%d", &Array2[i]);  // user input
    }
    
    printf("The New Array is:\n");
    display(Array2, n2);
    free(Array1);
}


void display(int *A, int n)  // function to display the array
{
    for(int i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
}