/*
Akshit Gandotra
Question 5 (Lab)
Find the product of two matricies using pointer
*/

#include <stdio.h>
#include <stdio.h>

int main()
{
    int row, column;
    printf("Enter the Number of rows and columns in a Matrix:\n");
    scanf("%d %d", &row, &column);
    int Arr1[row][column];
    int Arr2[row][column];
    int Result[row][column];
    printf("Enter Elements for Array 1\n");
    input((int *)Arr1, row, column);  // function call to input the elements of the matrix
    printf("Enter Elements for Array 2\n");
    input((int *)Arr2, row, column);  // function call to input the elements of the matrix
    printf("Array 1 is :\n");
    display((int *)Arr1, row, column);  // function call to display the matrix
    printf("Array 2 is :\n");
    display((int *)Arr2, row, column);  // function call to display the matrix
    product((int *)Result, row, column, Arr1, Arr2);  // function call to find the product of the matrix
    printf("Product of Arrays :\n");
    display((int *)Result, row, column);  // function call to display the matrix
}


void input(int *A, int R, int C)  // function to input the elements of the matrix
{
    for(int i = 0; i<R; i++)
    {
        for(int j = 0; j<C; j++)
        {
            printf("Enter a Number \n");
            scanf("%d", ((A+i*C)+j) );  // user input
        }
    }
}

void display(int *A, int R, int C)  // function to display the matrix
{
    for(int i = 0; i < R; i++)  // loop to access all the indexes of the matrix
    {
        for(int j = 0; j < C; j++)    
        printf("%d \t", *((A + i * C) + j));              
        printf("\n");
    }
}

void product( int *Res, int R, int C, int A1[R][C], int A2[R][C] )  // function to calculate the product of two matrices
{
    for (int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            int sum = 0; 
            for(int k = 0; k < C; k++)
            sum +=  *(*(A1 + i) + j) * *(*(A2 + j) + k);  // calculating the elements of the matrix
            *((Res + i * R) + j ) = sum;
        }
    }
}