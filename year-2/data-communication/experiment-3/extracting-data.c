// Code by Desh Iyer

#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX_SIZE 100

int main() {
    printf("Code by Desh Iyer, SAP Id 500081889\n");
    printf("Extracting Data from bit stuffed stream taking the flag pattern as {1, 1, 1, 0, 0, 0}\n\n");

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

    int resultArray[MAX_SIZE];
    int resultSize = dataStreamSize - 2 * flagSize;

    int count = 0;
    for (int i = 0; i < dataStreamSize; i++) {
        if (dataStream[i] == flag[i]) {
            count++;
        }

        if (count == flagSize) {
            for (int j = 0; j < resultSize; j++) {
                resultArray[j] = dataStream[flagSize + j];
            }
        }
    }

    for (int i = 0; i < resultSize; i++) {
        printf("%d ", resultArray[i]);
    }
}