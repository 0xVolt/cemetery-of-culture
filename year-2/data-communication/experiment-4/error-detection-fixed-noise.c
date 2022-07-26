// Code by Desh Iyer

// Taking noise array to be fixed

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 6

int arrayToNum(int *, int);

int main() {
    int dataFrameSize;
    int dataFrame[MAX_SIZE];
    int noise[] = {0, 0, 0, 0, 0, 1};
    int resultantFrame[MAX_SIZE];
    

    printf("Code by Desh Iyer, SAP Id 500081889\n");

    printf("Enter the size of the data frame: ");
    scanf("%d", &dataFrameSize);

    printf("Enter the data frame of %d bits:\n", dataFrameSize);
    for (int i = 0; i < dataFrameSize; i++) {
        scanf("%d", &dataFrame[i]);
    }

    printf("\n\nGiven Data Frame:\n");
    for (int i = 0; i < dataFrameSize; i++) {
        printf("%d ", dataFrame[i]);
    }

    printf("\n\nNoise Array:\n");
    for (int i = 0; i < dataFrameSize; i++) {
        printf("%d ", noise[i]);
    }
    
    int intDataFrame = arrayToNum(dataFrame, dataFrameSize);
    int intNoise = arrayToNum(noise, dataFrameSize);

    int binary1 = intDataFrame;
    int binary2 = intNoise;

    int i = 0, remainder = 0;
    while (binary1 != 0 || binary2 != 0){
        resultantFrame[i++] =  (binary1 % 10 + binary2 % 10 + remainder) % 2;
        remainder = (binary1 % 10 + binary2 % 10 + remainder) / 2;
        binary1 = binary1 / 10;
        binary2 = binary2 / 10;
    }

    if(remainder != 0)
        resultantFrame[i++] = remainder;

    --i;
    printf("\n\nResultant Frame = Data Frame + Noise:\n");
    while (i >= 0)
        printf("%d ", resultantFrame[i--]);\

    int sizeResultantDataFrame = sizeof(resultantFrame) / sizeof(resultantFrame[0]);
    int intResultantDataFrame = arrayToNum(resultantFrame, sizeResultantDataFrame);

    if (intDataFrame == intResultantDataFrame) {
        printf("\n\nThere IS NO error in the received data!");
    } else {
        printf("\n\nThere IS an error in the received data!");
    }
}

int arrayToNum(int arr[],int n) {
    char str[6][3];
    char number[13] = {'\n'};
    int i;

    for(i=0;i<n;i++)    sprintf(str[i],"%d",arr[i]);
    for(i=0;i<n;i++)    strcat(number,str[i]);

    i = atoi(number);
    return i;
}