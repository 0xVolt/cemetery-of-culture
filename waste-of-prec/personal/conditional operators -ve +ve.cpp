#include<iostream.h>
#include<conio.h>

void main() {
 clrscr();
 int n;
 cout<<"Enter an integer\n";
 cin>>n;
 (n>0)?cout<<"Positive!!":(n==0)?cout<<"Number entered is 0":cout<<"Negative";
 getch();
}