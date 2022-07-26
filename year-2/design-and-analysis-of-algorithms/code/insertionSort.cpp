#include <iostream>
using namespace std;

void insertionSort(int *, int);
void displayArray(int *, int);

int main() {
    int n;

    cout << "Number of elts: ";
    cin >> n;

    int array[n];

    cout << "Enter array:\n";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    cout << "\nUnsorted array:\n";
    displayArray(array, n);

    insertionSort(array, n);

    cout << "\nSorted Array:\n";
    displayArray(array, n);

    return 0;
}

void insertionSort(int *array, int len) {
    int j;
    for (int i = 1; i < len; i++) {
        j = i;
        while (j > 0 && array[j - 1] > array[j]) {
            int temp = array[j - 1];
            array[j - 1] = array[j];
            array[j] = temp;

            j--;
        }
    }
}

void displayArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
}