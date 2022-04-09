#include <stdio.h>
#include <stdlib.h>

int main() {
    char c[1000];
    // file pointer is declared
    FILE *fptr;
    if ((fptr = fopen("file.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }

    // reads text until newline is encountered
    fscanf(fptr, "%[^\n]", c);
    printf("Data from the file:\n%s", c);
    // closing file
    fclose(fptr);

    return 0;
}