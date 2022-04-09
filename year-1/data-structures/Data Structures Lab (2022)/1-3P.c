/*
Akshit Gandotra
Question 3 (Practice)
Store 'n' numbers in an array in Ascending or Descending Order. Conduct a Binary Search for a given number and report success or failure in the form of a suitable message.
*/
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the Size of Array\n");
    scanf("%d", &n);
    int Arr[n];  // array initialization
    input((int *)Arr, n);  // function call to input data in the Array
    printf("The Array is :\n");    
    display(n, Arr);  // function call to display data in the Array
    if(Arr[0] < Arr[1])
    Asc_Search(n, Arr);  // function call to search for a data in the Array in AscendingOrder
    else
    Des_Search(n, Arr);  // function call to search for a data in the Array in DescendingOrder
}


void input(int *A, int n)  // function to input data in the Array
{
    for(int i = 0; i < n; i++)
    {
        printf("Enter a Number in Ascending/Descending Order \n");
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

void Asc_Search (int n, int A[n])  // function to search for a data in the Array is Ascending Order
{
    int num;
    printf("Enter a Number to Search \n");
    scanf("%d", &num);
    int beg = 0;
    int end = n;
    int mid;
    int c = 0;
    while(beg <= end)
    {
        mid = (beg+end)/2;
        if (A[mid] == num)
        {
            printf("Number %d found at position %d in the Array\n", num, (mid + 1));
            c++;
            break;
        }
        else if(A[mid] > num)
        {
            end = mid;
        }
        else if(A[mid] < num)
        {
            beg = mid;
        }
    }
    if(c == 0)
    printf("Number %d is NOT present in the Array\n", num);
}

void Des_Search (int n, int A[n])  // function to search for a data in the Array in DescendingOrder
{
    int num;
    printf("Enter a Number to Search:\n");
    scanf("%d", &num);
    int beg = 0;
    int end = n;
    int mid;
    int c = 0;
    while(beg <= end)
    {
        mid = (beg + end)/2;
        if (A[mid] == num)
        {
            printf("Number %d found at position %d in the Array\n", num, (mid + 1));
            c++;
            break;
        }
        else if(A[mid] < num)
        {
            end = mid;
        }
        else if(A[mid] > num)
        {
            beg = mid;
        }
    }
    if(c == 0)
    printf("Number %d is NOT present in the Array\n", num);
}