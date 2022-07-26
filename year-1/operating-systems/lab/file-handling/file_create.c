#include <stdio.h>
#include <stdlib.h> // for exit()

void main() {
    FILE *fout;

    if (fout == NULL) {
        printf("File not created!");
        exit(0);
    }

    fout = fopen("file.txt", "w");
    fclose(fout);

    printf("A blank file has been created!");
}