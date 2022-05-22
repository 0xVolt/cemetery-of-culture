#include<iostream.h>
#include<conio.h>

int Palindrome(int a)
{
 int d,r=0;
 int a1=a;
 while(a>0)
 	{
    d=a%10;
    r=(r*10)+d;
    a=a/10;
   }
 if(a1==r)
 	return 1;
   else return 0;
}

void main()
{clrscr();
 cout<<"Enter a number = ";
 int x;
 cin>>x;
 if(Palindrome(x)==1)
 	cout<<"Palimdrome!!";
   else cout<<"Not a palidrome!!";
 getch();
}
