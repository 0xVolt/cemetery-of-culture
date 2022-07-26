#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void check(char a[],char ch)
{
 int i,s=0;
 for(i=0;a[i]!='\0';++i)
 	if(ch==a[i])
   	s=s+1;
 cout<<"Number of times character is present is = "<<s;
}

void main()
{
 clrscr();
 char x,b[50];
 cout<<"Enter a string\n";
 gets(b);
 cout<<"Enter character to check\n";
 cin>>x;
 check(b,x);
 getch();
}