#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char string[25];

    printf("Enter a string in uppercase: ");
    gets(string);

    for (int i = 0; i < strlen(string); i++) {
        if (isupper(string[i])) {
            string[i] = tolower(string[i]);
        }
    }

    printf("\nThe resultant lowercase string is: ");
    puts(string);

    return 0;
}