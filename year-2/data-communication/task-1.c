// Code by Desh Iyer

// ----------------------------------------------------------------------------------------

// Task
// 1. Bit-wise operator in C programming
// 2. Array and Pointers

// Problem Statement
// Store two binary strings and perform logical operation.
// String 1, A - 11001
// String 2, B - 00110
// (a.) A'
// (b.) B'
// (c.) A + B [binary-addition]

// ----------------------------------------------------------------------------------------

// Include libraries
#include <stdio.h>
#include <string.h>
#include <math.h>

// Function declarations
int add(int, int);
int toInt(char [], int);
int toBin(int);
void compliment(char [], int);

// Main function
int main() {
    int len;
    char string1[16], string2[16];

    // Input length
    printf("Enter length of binary strings: ");
    scanf("%d", &len);

    // Input first string
    fflush(stdin);
    printf("Enter the first binary string: ");
    scanf("%s", string1);

    // Input second string
    fflush(stdin);
    printf("Enter the second binary string: ");
    scanf("%s", string2);

    // Print compliment of first 
    printf("\nCompliment of first binary string: ");
    compliment(string1, len);

    // Print compliment of second 
    printf("\nCompliment of second binary string: ");
    compliment(string2, len);

    // Print the sum of the strings by converting the strings to ints and then finding their binary sum before changing the result to binary
    printf("\nSum of the binary strings: %d", toBin(
            add(
                toInt(string1, len), toInt(string2, len)
            )
        )
    );
} // End of main function

// Function to find binary addition of two ints
int add(int x, int y) {
    return (x ^ y) + (2 * (x & y));
}

// Function to convert binary string to int
int toInt(char s[], int len) {
    int sum = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == '1') {
            sum += pow(2, len - i - 1);
        }
    }
    return sum;
}

// Function to convert int to binary (stored in int)
int toBin(int n) {
    long bin = 0;
    int rem, i = 1;

    while (n != 0) {
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }

    return bin;
}

// Function to print the compliment of a binary string
void compliment(char str[], int len) {
    for (int i = 0; i < len; i++) {
        if (str[i] == '1')
            printf("0");
        else
            printf("1");
    }
}

// Resources
// 1. https://www.tutorialspoint.com/cprogramming/c_operators.htm
// 2. https://www.youtube.com/watch?v=jlQmeyce65Q
