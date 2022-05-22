#include<iostream.h>
#include<conio.h>
struct distance
{
 int feet,inches;
};

distance sum(distance d1, distance d2)
{
 distance d3;
 d3.feet = d1.feet + d2.feet + (d1.inches + d2.inches)/12;
 d3.inches = (d1.inches + d2.inches)%12;
 return d3;
}

void main()
{clrscr();
 distance a,b,c;
 cout<<"Enter distance 1 in inches and feet = \n" ;
 cin>>a.inches>>a.feet;
 cout<<"Enter distance 2 in inches and feet = \n";
 cin>>b.inches>>b.feet;
 c.inches = (a.inches + b.inches)%12;
 c.feet = a.feet + b.feet+(a.inches+b.inches)/12;
 cout<<"\n\nAdded distance = \n"<<c.feet<<" Feet\n"<<c.inches<<" Inches";
 getch();
}
