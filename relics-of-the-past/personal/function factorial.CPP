#include<iostream.h>
#include<conio.h>

long factorial(int a) {
 int i,f=1;
 for(i=2;i<=-a;++i) {
  f*=i;
 }
 return f;;
}

void main() {
 clrscr();
 cout<<"Enter a number\n";
 int n;
 cin>>n;
 cout<<"Factorial of the number is \n"<<factorial(n);
 getch();
 }

