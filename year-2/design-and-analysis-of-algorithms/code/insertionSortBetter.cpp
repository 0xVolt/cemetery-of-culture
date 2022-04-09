#include <iostream>
using namespace std;

void displayArray(int *, int);
void insertionSortArray(int *, int);
void swap(int *, int *);

int main() {
    int n;

    cout << "Enter number of elts: ";
    cin >> n;

    int A[n];

    cout << "Enter elts of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i]; 
    }

    cout << "\nUnsorted Array: ";
    displayArray(A, n);

    insertionSortArray(A, n);

    cout << "\nSorted Array: ";
    displayArray(A, n);

    return 0;
}

void displayArray(int *A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}

void insertionSortArray(int *A, int n) {
    int j;

    for (int i = 1; i < n; i++) {
        j = i;

        while (j > 0 && A[j - 1] > A[j]) {
            swap(A[j - 1], A[j]);

            j--;
        }
    }
}

void swap(int *A, int *B) {
    // With third var
    // int temp;
    // temp = *num1;
    // *num1 = *num2;
    // *num2 = temp;

    // Without third var
    // A = A operation B
    // B = A inverse-operation B
    // A = A inverse-operation B 
    *A = *A + *B;
    *B = *A - *B;
    *A = *A - *B;
}