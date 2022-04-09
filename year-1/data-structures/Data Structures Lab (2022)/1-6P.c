/*
Akshit Gandotra
Question 6 (Practice)
Find the total number of Alphabets, Digits or Special Characters in a String. 
*/

#include <stdio.h>

int main ()
{
    char str[100];
    input((char *)str);  // function call to input the String 
    display((char *)str);  // function call to display the string
    count((char *)str);  // function call to count the number of Alphabets, Digits or Special Characters in a String
}


void input(char *S)  // function to input the String 
{
    printf("Enter a String\n");
    gets(S);
}

void display (char *S)  // function to display the string
{
    printf("The String is :- \n");
    puts(S);
}

void count(char *S)  // function to count the number of Alphabets, Digits or Special Characters in a String
{
    int alp = 0;
    int num = 0;
    int spc = 0;
    for(int i = 0 ; S[i] != '\0' ; i++)
    {
        if((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z') )  // alphabet count
        alp ++ ;
        else if(S[i] >= '0' && S[i] <= '9')  // digit count
        num ++ ;
        else if(S[i] == '@' || S[i] == '#' || S[i] == '$' || S[i] == '%' || S[i] == '!')  // special character count
        spc ++;
    }
    printf("Number of Alphabets in the String :- %d \n" , alp);
    printf("Number of Digits in the String :- %d \n" , num);
    printf("Number of Special Characters in the String :- %d \n" , spc);
}