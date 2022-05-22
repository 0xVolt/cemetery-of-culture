#include<iostream.h>
#include<conio.h>

void main() {
 clrscr();
 int days,years,weeks,remdays;
 cout<<"Enter number of days = ";
 cin>>days;
 years = days/365;
 remdays = days%365;
 weeks = remdays/7;
 int D;
 D = remdays%7;
 cout<<"Years = "<<years<<"\nWeeks = "<<weeks<<"\nRemaining number of days = "<<D;
 getch();
}
