#include<iostream.h>
#include<conio.h>

/*Displaying the result in main after initialization
as well as in the function shows
the reference swapping more clearly*/

void swap(int &a, int &b)
{
 int t;
 t=a;
 a=b;
 b=t;
 cout<<"a = "<<a<<" ";
 cout<<"b = "<<b<<endl;;
}

void main()
{
 clrscr();
 int x, y;
 cout<<"Enter values for x and y\n";
 cin>>x>>y;
 cout<<"a = "<<x<<" "<<"b = "<<y<<endl;;
 swap(x,y);
 cout<<"a = "<<x<<" "<<"b = "<<y<<endl;;
 getch();
}