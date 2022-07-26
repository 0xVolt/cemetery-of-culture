// Code by Desh Iyer
// Problem Statement 2

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double calculateN(double H, double L) {
    double N = 2 * H * log2(L);
    return N;
}

int main() {
    int *bitStream;
    int n;
    double L, H, N;

    printf("Enter the size of bit stream: ");
    scanf("%d", &n);

    bitStream = (int *) malloc(n * sizeof(int));

    printf("Enter the bit stream:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bitStream[i]);
    }

    L = pow(2, n);

    printf("Enter the bandwidth (in kHz): ");
    scanf("%lf", &H);
    H *= 1000;

    N = calculateN(H, L);

    printf("\n\nCalculating values:");

    printf("\nGiven bit stream: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", bitStream[i]);
    }
    
    printf("\nLength of bit stream = %d", n);
    printf("\nNumber of levels = %.2lf levels", L);
    printf("\nH = %.2lf Hz", H);
    printf("\nData Rate N = %.2lf Hz", N);
}