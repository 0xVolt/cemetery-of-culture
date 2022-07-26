#include <stdio.h>

#define M 3

struct STUDENT {
    long int SAP;
};

int get_hash_value(long int);

int main() {
    struct STUDENT S[M];

    printf("Enter the SAP ids of %d students:\n", M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &S[i]);
    }

    printf("Printing hash values of the SAP ids:\n");
    for (int i = 0; i < M; i++) {
        printf("\nSAP id %d: %d", (i + 1), get_hash_value(S[i].SAP));
    }
}

int get_hash_value(long int SAP) {
    int hash_value, last_digits;

    /* To get the last three digits */
    last_digits = SAP % 1000;
    
    hash_value = last_digits % M;

    return hash_value;
}