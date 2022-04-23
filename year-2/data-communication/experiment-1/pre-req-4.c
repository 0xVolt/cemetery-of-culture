// Code by Desh Iyer

// PROBLEM STATEMENT
// Design program to add two strings (using pointers)

// Include Libraries
#include <stdio.h>

int main() {
    char string1[100], string2[100];

    printf("\nEnter the first string: ");
    gets(string1);

    printf("\nEnter the second string to be concatenated: ");
    gets(string2);

    char *a = string1;
    char *b = string2;

    while(*a) {
        a++;
    }
    
    while(*b) {
        *a = *b;
        b++;
        a++;
    }

    *a = '\0';

    printf("\nThe string after concatenation is: %s", string1);

    return 0;
}