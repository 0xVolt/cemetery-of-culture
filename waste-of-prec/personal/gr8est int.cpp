#include<iostream.h>
#include<conio.h>

void main() {
 clrscr();
 int b1,b2,a,b,c;
 cout<<"Enter 3 numbers\n";
 cin>>a>>b>>c;
 b1 = (a>b)?a:b;
 b2 = (b1>c)?b1:c;
 cout<<"The greatest integer is\n"<<b2;
 getch();
}