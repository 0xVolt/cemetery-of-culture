// Code by Desh Iyer
// Problem Statement 1

#include <stdio.h>

float baudRateEstimate(float, float, int);

int main() {
    int N;
    float c, r;

    printf("Enter data rate N: ");
    scanf("%d", &N);

    printf("Enter case factor c: ");
    scanf("%f", &c);

    printf("Enter ratio r: ");
    scanf("%f", &r);

    printf("Baud Rate calculated: %.2f baud(s)", baudRateEstimate(c, r, N));

    return 0;
}

float baudRateEstimate(float c, float r, int N) {
    float S = c * N * (1 / r);
    return S;
}