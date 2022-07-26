// Code by Desh Iyer

// Taking noise to be randomly generated

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX_SIZE 6

int arrayToNum(int *, int);
void initialiseArray(int *, int, int);
int countDigits(int);
void intToBin(int, int *);

int main() {
    int dataFrameSize;
    int dataFrame[MAX_SIZE];
    int noise[MAX_SIZE];
    int resultantFrame[MAX_SIZE];

    int dataRate, dataSize;
    int k = 0, sum = 0, tf, tb;

    printf("Code by Desh Iyer, SAP Id 500081889\n");

    printf("Input Data Size: ");
    scanf("%d", &dataSize);

    printf("Input Data Rate: ");
    scanf("%d", &dataRate);

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

    srand(time(0));

    // Initialising an upper and a lower limit to RNG
    int lower = 1;
    int upper = 64;
    int num = (rand() %
           (upper - lower + 1)) + lower;

    intToBin(num, noise);

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
        resultantFrame[i++] = (binary1 % 10 + binary2 % 10 + remainder) % 2;
        remainder = (binary1 % 10 + binary2 % 10 + remainder) / 2;
        binary1 = binary1 / 10;
        binary2 = binary2 / 10;
    }

    if(remainder != 0) 
        resultantFrame[i++] = remainder;

    --i;
    printf("\n\nResultant Frame = Data Frame + Noise:\n");
    while (i >= 0)
        printf("%d ", resultantFrame[i--]);

    // int sizeResultantDataFrame = sizeof(resultantFrame) / sizeof(resultantFrame[0]);
    // int intResultantDataFrame = arrayToNum(resultantFrame, sizeResultantDataFrame);

    // if (intDataFrame == intResultantDataFrame) {
    //     printf("\n\nThere IS NO error in the received data!");
    // } else {
    //     printf("\n\nThere IS an error in the received data!");
    // }
}

int arrayToNum(int arr[],int n){
    char str[6][3];
    char number[13] = {'\n'};
    int i;

    for(i=0;i<n;i++)    sprintf(str[i],"%d",arr[i]);
    for(i=0;i<n;i++)    strcat(number,str[i]);

    i = atoi(number);
    return i;
}

void initialiseArray(int *a, int size, int num) {
    for (int i = 0; i < size; ++i, num /= 10)
        a[(size - 1) - i] = num % 10;
}

int countDigits(int n) {
    int count = 0;

    do {
        n /= 10;
        ++count;
    } while (n != 0); 

    return count;
}

void intToBin(int dec, int bin[]) {
    for(int i = 0; i < MAX_SIZE; i++){
        bin[i] = 1 & (dec >> i);
    }
}