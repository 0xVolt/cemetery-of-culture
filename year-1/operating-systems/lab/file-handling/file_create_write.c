#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fout;
    char data[100];
    fout = fopen("file.txt", "w");

    if (fout == NULL) {
        printf("File not created!");
    }
    else {
        printf("Enter the data to write to the file:\n");
        fgets(data, 100, stdin);
        fputs(data, fout);
        fclose(fout);
        printf("File successfully created!");
    }
}