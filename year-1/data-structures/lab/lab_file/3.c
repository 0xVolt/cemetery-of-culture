#include <stdio.h>

#define R 3
#define C 3

void calculateTranspose(int matrix[R][C]) {
    int transposeMatrix[R][C], i, j;

    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            transposeMatrix[j][i] = matrix[i][j];
        }
    }

    printf("\nPrinting given matrix:\n");

    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nPrinting Transpose of given matrix:\n");

    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            printf("%d ", transposeMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[R][C], i, j;

    printf("Enter the matrix whose transpose is to be calculated:\n");
    for (i = 0; i < R; i++) {
        printf("\nRow #%d: ", i + 1);
        for (j = 0; j < C; j++) {
            printf("Column #%d: ", j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    calculateTranspose(matrix);

    return 0;
}