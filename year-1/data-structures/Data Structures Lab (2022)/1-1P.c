/*
Akshit Gandotra
Question 1 (Practice)
Find the Transpose and Inverse of the Matrix.
*/

#include<stdio.h>
#include<math.h>			

// function declaration
void input(int *, int );
void display(int N, int [N][N]);
void transpose(int *, int N, int [N][N] );
void cofactor(int N, int [N][N]);
int determinant(int N, int [N][N]);
void inverse(int N, int [N][N], int [N][N]);

int main()
{
    int N;
    printf("Enter the order of a Square Matrix:\n");
    scanf("%d", &N);
    int Arr[N][N];
    int Transpose[N][N];
    printf("Enter the elements in the Matrix:\n");
    input((int *)Arr, N);  // function call to input elements of the Matrix
    printf("The Matrix is :\n");
    display(N, Arr);  // function call to display the elements of the Matrix
    printf("The Transpose of Matrix is :\n");
    transpose((int *)Transpose, N, Arr);  // function call to find the transpose of the Matrix
    display(N, Transpose);  // function call to display the elements of the Matrix
    if (determinant(N, Arr) == 0)
    printf("The Inverse of a Singular Matrix does not Exist.\n");
    else
    cofactor(N, Arr);  // function call to calculate inverse
}

void input(int *A, int N)  // function to input elements of the Matrix
{
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)  
        {
            printf("Enter a Number \n");
            scanf("%d", ((A + i * N) + j) );
        }
    }
}

void display (int N, int A[N][N])  // function to display the elements of the Matrix
{
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)  
        {
            printf("%d \t", A[i][j]);
        }
        printf("\n");
    }
}

void transpose(int *Transpose, int N, int A[N][N])  // function to find the Transpose of the Matrix
{
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)  
        {
            *((Transpose + i * N) + j) = A[j][i];
        }
    }
}

int determinant(int N, int A[N][N])  // function to calculate determinant
{
    int s = 1, det = 0;
    int B[N][N];
    int m, n;
    if (N == 1)
    return (A[0][0]);
    else
    {
        det = 0;
        for (int k = 0; k < N; k++)
        {
            m = 0;
            n = 0;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    B[i][j] = 0;
                    if (i != 0 && j != k)
                    {
                        B[m][n] = A[i][j];
                        if (n < (N - 2))
                        n++;
                        else
                        {
                            n = 0;
                            m++;
                        }
                    }
                }
            }
          det = det + s * (A[0][k] * determinant(N-1, B));
          s = -1 * s;
        }
    }
    return (det);
}
 
void cofactor(int N, int A[N][N])  // function to calculate cofactor
{
    int B[N][N], Fact[N][N];
    int m, n;
    for (int q = 0; q < N; q++)
    { 
        for (int p = 0; p < N; p++)
        {
            m = 0;
            n = 0;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (i != q && j != p)
                    { 
                        B[m][n] = A[i][j];
                        if (n < (N-2))
                        n++;
                        else
                        {
                            n = 0;
                            m++;
                        }
                     }
                }
            }
            Fact[q][p] = pow(-1, q + p) * determinant(N-1, B);
        }
    }
    inverse(N, A, Fact);
}
 
void inverse(int N, int A[N][N], int Fact[N][N])   // function to find the inverse of the Matrix
{
    int B[N][N];
    double Inv[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            B[i][j] = Fact[j][i];
        }
    }
    double d = determinant(N, A);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Inv[i][j] = B[i][j] / d;
        }
    }
    printf("\nThe inverse of matrix:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("\t%f", Inv[i][j]);
        }
        printf("\n");
    }
}