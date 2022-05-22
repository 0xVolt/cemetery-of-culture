#include<iostream.h>
#include<conio.h>
#include<stdio.h>

int i;

class STUDENT
	{
   	long int Grno;
      char Name[20];
      float Marks[5];
      float Total,Percentage;
      void Calculate();

      public :

      void takedata();
      void displaydata();
   };

void STUDENT :: Calculate()
	{
      for(i=0;i<5;++i)
      	Total+=Marks[i];
      Percentage = Total * (1.0/5.0);
   }

void STUDENT :: takedata()
	{
   	cout<<"Enter Grno : ";
      cin>>Grno;
      cout<<"Enter Name of the Student : ";
      gets(Name);
      cout<<"Enter marks in 5 subjects \n";
      for(i=0;i<5;++i)
      	cin>>Marks[i];
   }

void STUDENT :: displaydata()
	{
      Calculate();
   	cout<<"Grno of the Student :  "<<Grno;
      cout<<"\nName of the Student : "<<Name;
      cout<<"\nMarks in 5 subjects : \n";
      for(i=0;i<5;++i)
      	cout<<Marks[i]<<endl;
      cout<<"\nTotal Marks = "<<Total;
      cout<<"\nPercentage = "<<Percentage<<'%';
   }

void main()
	{
      clrscr();
   	STUDENT s1;
      s1.takedata();
      s1.displaydata();
      getch();
   }
