/*
Akshit Gandotra
Question 4 (Lab)
Program to calculate the sum of Rows and Columns of a Matrix of order (row * column)
*/

#include <stdio.h>

int main()
{
    int row, column;
    printf("Enter the Number of rows and columns in a Matrix\n ");
    scanf("%d %d", &row, &column);
    int Arr[row][column];
    input((int *)Arr, row, column);  // function call to input elements
    display((int *)Arr, row, column);  // function call to display the array
    RowSum((int *)Arr, row, column);  // function call to calculate the sum of each row
    ColumnSum((int *)Arr, row, column);  // function call to calculate the sum of each column
}


void input(int *A, int R, int C)  // function to input the elements of the array
{
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            printf("Enter a Number\n");
            scanf("%d", ((A + i * C) + j));  // user input
        }
    }
}

void display(int *A, int R, int C)  // function to display the array
{
    for(int i = 0; i < R; i++)  // accessing all indexes of array
    {
        for(int j = 0; j < C; j++)    
        printf("%d \t ", *((A + i * C) + j));              
        printf("\n");
    }
}

void RowSum(int *A, int R, int C)  // function to calculate the sum of each row
{
    for(int i = 0; i < R; i++)          
    {
        int sum = 0;
        for(int j = 0; j < C; j++)
        sum += *((A + i * C) + j);  // calculating sum of each row
        printf("The sum of Row Number %d is %d \n", (i + 1), sum);  // display sum
    }
}

void ColumnSum(int *A, int R, int C)  // function to calculate the sum of each column
{
    for(int i = 0; i < C; i++)           
    {
        int sum = 0;
        for(int j = 0; j < R; j++)
        sum += *((A + i * C) + j);  // calculating sum of columns
        printf("The sum of Column Number %d is %d \n", (i + 1), sum); //Displaying the sum
    }
}