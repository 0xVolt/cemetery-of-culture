// Code by Desh Iyer

// PROBLEM STATEMENT
// Design a program to read and write strings

// Include Libraries
#include <stdlib.h>
#include <stdio.h>

int main() {
    char string[20];

    printf("Enter the string: ");
    gets(string);

    char *ptr = string;

    while (*ptr != '\0') {
        printf("%c", *ptr);

        ptr++;
    }
}