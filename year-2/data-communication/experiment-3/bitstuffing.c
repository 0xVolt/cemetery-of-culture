// Code by Desh Iyer

#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX_SIZE 100

void mergeArray(int a[], int n1, int b[], int n2, int mer[]) {
	int i, j, k, n3;
	j = k = 0;
	n3 = n1 + n2;	
	for(i = 0; i < n3;) {
		if(j < n1 && k < n2) {
			if(a[j] < b[k]) {
				mer[i] = a[j];
				j++;
			} else {
				mer[i] = b[k];
				k++;
			}
			i++;
		} else if(j == n1) {
			while(i < n3) {
				mer[i] = b[k];
				k++;
				i++;
			}
		} else {
			while(i < n3) {
				mer[i] = a[j];
				j++;
				i++;
			}
		}
	}
}

int main() {
    printf("Code by Desh Iyer, SAP Id 500081889\n");
    printf("Bit stuffing taking the flag pattern as {1, 1, 1, 0, 0, 0}\n\n");

    int flag[] = {1, 1, 1, 0, 0, 0};
    int flagSize = sizeof(flag) / sizeof(int);

    int dataStream[MAX_SIZE];

    int dataStreamSize;
    printf("Enter size of the bit stream: ");
    scanf("%d", &dataStreamSize);

    printf("Enter data bit stream: ");
    for (int i = 0; i < dataStreamSize; i++) {
        scanf("%d", &dataStream[i]);
    }

    int resultSize = 2 * flagSize + dataStreamSize;
    int resultStream[MAX_SIZE];
    
    int tempArray[MAX_SIZE];
    mergeArray(flag, flagSize, dataStream, dataStreamSize, tempArray);
    mergeArray(tempArray, flagSize + dataStreamSize, flag, flagSize, resultStream);

    printf("Result array:\n");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", resultStream[i]);
    }
}