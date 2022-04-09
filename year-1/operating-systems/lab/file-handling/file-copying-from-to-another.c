#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* To take command-line args */
int main(int argc, char *argv[]) {
    /* Check if sufficient args are passed */
    if (argc == 3) {
        FILE *fin, *fout;

        /* Open files */
        fin = fopen(argv[1], "r");
        fout = fopen(argv[2], "w");

        if (!fin || !fout) {
            printf("Error opening files...");
            exit(1);
        }


        char ch;

        /* Read file1 character by character */
        ch = fgetc(fin);
        while (ch != EOF) {
            /* Write the character that was read into file2 */
            fputc(ch, fout);
            /* Change value of character to the next char in file 1 */
            ch = fgetc(fin);
        }

        printf("File contents successfully transferred from %s to %s\n", argv[1], argv[2]);

        /* Close files */
        fclose(fin);
        fclose(fout);
    } else {
        /* Print error messages */
        printf("Expected 2 arguments...\nFormat: ./a.exe fileToRead fileToWrite");
        exit(1);
    }
}