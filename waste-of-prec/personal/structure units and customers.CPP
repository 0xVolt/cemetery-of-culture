#include<iostream.h>
#include<conio.h>
#include<stdio.h>

struct customer
{
 int idno;
 char name[50];
 float units;
 float amt;
};

void main()
{
 clrscr();
 customer s[100];
 int i,n;
 cout<<"How many customers??";
 cin>>n;
 for(i=0;i<=n;++i)
 	{
    cout<<"\nEnter ID number = ";
    cin>>s[i].idno;
    cout<<"\nEnter name of the customer\n";
    gets(s[i].name);
    cout<<"Enter number of units consumed = ";
    cin>>s[i].units;
    if(s[i].units>1||s[i].units<100)
    	s[i].amt=0.2*s[i].units;
    else if(s[i].units<300||s[i].units>101)
    	s[i].amt=0.4*(s[i].units-101)+100*0.2;
    else if(s[i].units>300)
    	s[i].amt=0.5*(s[i].units-300)+200*0.4+100*0.1;
    cout<<endl;
    cout<<endl;
   }

 for(i=0;i<=n;++i)
 	cout<<"\nID number = "<<s[i].idno<<"\nName of customer = "<<s[i].name<<"\nNumber of units consumed = "<<s[i].units<<"\n\nAmount to be paid = "<<s[i].amt;
 getch();
}
