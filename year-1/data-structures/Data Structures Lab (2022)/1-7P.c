/*
Akshit Gandotra
Question 7 (Practice)
Find whether the string is Palindrome or not. 
*/

#include <stdio.h>
#include <string.h>

int main ()
{
    char str[100];
    input((char *)str);  // function call to input the String 
    display((char *)str);  // function call to display the string
    check((char *)str);  // function call to check for Palindrome string
}


void input(char *S)  // function to input the String 
{
    printf("Enter a String\n");
    gets(S);
}

void display (char *S)  // function to display the string
{
    printf("The String is :\n");
    puts(S);
}

void check (char *S)  // function to check for Palindrome string
{
    int len = strlen(S);
    int L = len - 1;
    int c = 0;
    for(int i = 0; i < len; i ++)
    {
        if(S[i] != S[L--])
        c++;
    }
    if ( c > 0)
    printf("The given String is NOT a Palindrome String.\n");
    else
    printf("The given String is a Palindrome String.\n");
}