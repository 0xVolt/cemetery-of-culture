#include <stdio.h>
#include <stdlib.h>

int main() {
    char string[80];
    FILE *fout; /* File ptr */

    /* Open/Create file testFile.txt in write mode */
    fout = fopen("testFile.txt", "w");

    /* Check if file was created */
    if (fout == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    /* Enter string to write */
    printf("Enter text to write to file:\n");
    scanf("%s", string);

    /* Write the string to the file */
    fprintf(fout, "%s", string);

    /* Close the file */
    fclose(fout);

    return 0;
}