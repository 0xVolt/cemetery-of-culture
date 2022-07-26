/*
Akshit Gandotra
Question 8 (Practice)
Count the number of words in a String.
*/

#include <stdio.h>
#include <string.h>

int main ()
{
    char str[100];
    input((char *)str);  // function call to input the String 
    display((char *)str);  // function call to display the string
    count((char *)str);  // function call to count the Number of Words in the String.
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

void count (char *S)  // function to count the Number of Words in the String.
{
    int len = strlen(S);
    int count = 0;
    for(int i = 0; i < len-1; i++)
    {
        if(S[i+1] == ' ' || S[i+1] == '\n' || S[i+1] == '\t' || S[i+1] == '\0' || (i+1)==(len-1) || S[i+1] == '.' || S[i+1] == ',' || S[i+1] == '?' || S[i+1] == '!' )
        count ++;
    }
    printf("Number of Words in the String is %d.",count);
}