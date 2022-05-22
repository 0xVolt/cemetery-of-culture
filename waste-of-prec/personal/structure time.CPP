#include<iostream.h>
#include<conio.h>
struct time
{
 int hr,mn,ss;
}t1={0,0,0},t2,t3;
void main()
{
 clrscr();
 t2=t1;
 cout<<"Initial values for T1 = \n"<<t1.hr<<" Hours\n"<<t1.mn<<" Minutes\n"<<t1.ss<<" Seconds\n\n";
 cout<<"Initial values for T2 = \n"<<t2.hr<<" Hours\n"<<t2.mn<<" Minutes\n"<<t2.ss<<" Seconds\n\n";
 cout<<"Enter values for T1\n";
 cin>>t1.hr>>t1.mn>>t1.ss;
 cout<<"Enter values for T2\n";
 cin>>t2.hr>>t2.mn>>t2.ss;
 t3.hr=0;
 t3.mn=0;
 t3.ss=0;
 int s1,s2;
 s1 = t1.ss+t2.ss;
 t3.mn += (s1/60);
 t3.ss += (s1%60);
 s2 = t1.mn+t2.mn;
 t3.mn+=(s2%60);
 t3.hr+=(s2/60);
 t3.hr=t1.hr+t2.hr;
 cout<<"Values for time T3\n";
 cout<<t3.hr<<" Hours\n"<<t3.mn<<" Minutes\n"<<t3.ss<<" Seconds";
 getch();
}

