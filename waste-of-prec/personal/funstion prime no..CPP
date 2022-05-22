#include<iostream.h>
#include<conio.h>

int Prime()
{
 int x,i,c=0;
 cout<<"Enter a number = ";
 cin>>x;
 for(i=1;i<x;++i)
 	if(x%i==0)
   	c++;
 if(c>1)
 	return 0;
   else
   	return 1;
}

void main()
{
 clrscr();
 if(Prime()==1)
 	cout<<"Prime number!!!";
   else
   	cout<<"Composite number!!";
 getch();
}