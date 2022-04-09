/*
Akshit Gandotra
Question 3 (Lab)
Program to convert upper case string to lower case string using Loop
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];  // initialize a variable
    printf("Enter a String \n");
    gets(str);  // accept a string
    display(str);  // function call to display string
    convert(str);  // function call to change case
    printf("The string in Lower case is:\n");
    display(str);  // function to display the string
}


void convert(char *S)  // function to change case
{
    char *str = S;
    int i;
    for(i = 0; i < str[i] != '\0'; i++)
    {
        if( str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;  // convert upper case to lower case
        }
        else 
        continue;
    }
}
void display(char *S)  // function to display the string
{
    puts(S);  // print the string
}