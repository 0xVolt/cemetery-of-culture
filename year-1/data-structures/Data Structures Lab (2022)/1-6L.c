/*
Akshit Gandotra
Question 6 (Lab)
Store 'n' numbers in an array. Conduct a Linear Search for a given number and report success or failure in the form of a suitable
message.
*/

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the Size of Array \n");
    scanf("%d", &n);
    double Arr[n];  // initialize array
    input((double *)Arr, n);  // function call to input data in array
    printf("The Array is :\n");    
    display(n, Arr);  // function call to display data in array
    search(n, Arr);  // function call to search for a data in array
}


void input(double *A, int n)  // function to input data in array
{
    for(int i = 0; i < n; i++)
    {
        printf("Enter a Number \n");
        scanf("%lf", &A[i]);  // user input
    } 
}

void display(int n, double A[n])  // function to display data in array
{
    for(int i = 0; i < n; i++)
    {
        printf("%lf \t", A[i]);
    }
    printf("\n");
}

void search(int n, double A[n])  // function to search for a data in array
{
    double num;
    printf("Enter a Number to Search \n");
    scanf("%lf", &num);  // user input
    int c = 0;
    for(int i = 0; i < n; i++)
    {
        if(A[i] == num)
        {
            c++;
            printf("Number %lf found at position %d.", num, (i + 1));  // if number is found
            break;
        }
    }
    if(c == 0)
    printf("Number %lf not present in the Array.", num);  // if number is not found
}