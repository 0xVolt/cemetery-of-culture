/*
Akshit Gandotra
Question 2 (Pratice)
Find the matrix of given order (m *  nj;n) is a Spare Matrix or not. Assume that the Matrix is Spare Matrix if more than half of
the elements of the Matrix are 0.
*/
#include <stdio.h>

int main()
{
    int m, n;
    printf("Enter the Number of rows and columns in a Matrix \n");
    scanf("%d %d", &m, &n);
    int Arr[m][n];  // create matrix
    input((int *)Arr, m, n);  // function call to input the elements of the Matrix
    printf("The Matrix is :\n");
    display((int *)Arr, m, n);  // function call to display the Matrix
    calculate(m, n, Arr);  // function call to check whether the matrix is a Spare Matrix
}


void input(int *A, int R, int C)  // function to input the elements of the Matrix
{
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            printf("Enter a Number:\n");
            scanf("%d", ((A + i * C) + j));  // user input
        }
    }
}
void display(int *A, int R, int C)  // function to display the Matrix
{
    for(int i = 0; i < R; i++)  // loop to access all indexes of the Matrix
    {
        for(int j = 0; j < C; j++)    
        printf("%d \t", *((A + i * C) + j));              
        printf("\n");
    }
}

void calculate (int R, int C, int A[R][C])  // function to check whether the matrix is a Spare Matrix
{
    int total = R * C;
    int c = 0;
    for(int i = 0; i < R; i++)            
    {
        for(int j = 0; j < C; j++)
        {
            if (A[i][j] == 0)  // condition to check element for 0
            c++; 
        }
    }
    if ( c > (total/2))
    printf("The given Matrix is a Sparse Matrix.\n");
    else
    printf("The given Matrix is NOT a Sparse Matrix.\n");
}