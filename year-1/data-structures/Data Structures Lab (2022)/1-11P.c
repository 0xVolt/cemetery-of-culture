/*
Akshit Gandotra
Question 11 (Practice)
Add two Complex Numbers by passing structure to a function as argument.
*/
#include <stdio.h>

struct complex  // strucutre initialization
{
  int real;
  int imag;
};

struct complex addition(struct complex num1 , struct complex num2)  //function for the addition of two complex numbers
{
    struct complex result ;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return (result);
}

int main()
{
    struct complex num1, num2, result;
    printf("Enter details of Number 1\n");
    input(&num1);  // function call to input complex number
    printf("Enter details of Number 2\n");
    input(&num2);  // function call to input complex number
    printf("Complex Number 1 :- ");
    display(num1);  // function call to display the complex number
    printf("Complex Number 2 :- ");
    display(num2);  // function call to display the complex number
    result = addition (num1 , num2);  // function call for the addition of two complex numbers
    printf("Result of Two Complex Numbers :- \n");
    display(result);  // function call to display the complex number
}


void input(struct complex *element)  // function to input complex number
{
    printf("Enter Real part of the Number \n");
    scanf("%d" , &element->real);
    printf("Enter Imaginary part of the Number \n");
    scanf("%d" , &element->imag);
}

void display(struct complex num)  //function to display the complex number
{
    printf("%d + %di  \n" , num.real , num.imag);
}