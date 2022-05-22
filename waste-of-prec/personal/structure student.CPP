#include<iostream.h>
#include<conio.h>
#include<stdio.h>

struct student
{
 int rollno;
 char name[65];
 float marks[5],totm,avgm;
};

void main()
{clrscr();
 student s;
 cout<<"Enter student rollno. = ";
 cin>>s.rollno;
 cout<<"Enter name of the student = ";
 gets(s.name);
 cout<<"Enter marks in 5 subjects\n";
 int i;
 s.totm=0;
 s.avgm=0;
 for(i=0;i<5;++i)
 	{cin>>s.marks[i];
   s.totm+=s.marks[i];}
 s.avgm=s.totm/5;
 cout<<"\nStudent rollno = "<<s.rollno;
 cout<<"\nStudent name = "<<s.name;
 cout<<"\nMarks in 5 subjects\n";
 for(i=0;i<5;++i)
 	cout<<s.marks[i]<<endl;
 cout<<"St udents total marks = "<<s.totm;
 cout<<"\nStudents average marks = "<<s.avgm;
 getch();
}
