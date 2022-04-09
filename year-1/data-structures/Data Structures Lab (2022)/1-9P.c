/*
Akshit Gandotra
Question 9 (Practice)
Design a structure ‘product’ to store the details of the product purchased like product name, price per unit, number of quantities purchased, and amount spent. Get the name, price per unit, and the number of quantities purchased. Calculate the amount spent on the product and then display all the details of the purchased product using structure pointer.
*/

#include <stdio.h>
#include <string.h>
struct product  // structure initialization
{
   char name[100];
   float price;
   int quant;
   float totalprice;
};

int main()
{
    struct product prod;  // declaring structure variables
    struct product *p_prod;
    p_prod = &prod;
    input(p_prod);  // function call to input data in the variables
    print(p_prod);  // function call to print data of the Product
}


void input(struct product *i)  // function to input data in the variables
{
    printf("Enter Product Name, Price per Unit, and the Number of Quantaties Purchased :\n");
    gets(i -> name);  // user input
    scanf("%f", &i->price);  // user input
    scanf("%d", &i->quant);  // user input
    i -> totalprice = i -> price * i -> quant;  //Data initialization
}

void print(struct product *i)  // funtion to print data of the Product
{
    printf("Product Name : ");
    puts(i -> name );
    printf("Number of Quantities : %d \nPrice per unit : %f \nTotal Price : %f", i -> quant, i -> price, i -> totalprice);
}