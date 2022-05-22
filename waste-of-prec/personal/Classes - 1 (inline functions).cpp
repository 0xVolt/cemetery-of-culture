#include<iostream.h>
#include<stdio.h>
#include<conio.h>

int i;

class STUDENT
	{
   	private :

      int rno;
      char name[10];
      float marks[5];
      float total;
      void calculate()
      	{
          total = 0;
          for(i=0;i<5;++i)
          	total+=marks[i];
         }

      public :

      void readinfo()
      	{
         	cout<<"Enter Student gr no = ";
            cin>>rno;
            cout<<"Enter the name of the Student = ";
            gets(name);
            cout<<"Enter marks in 5 subjects\n";
            for(i=0;i<5;++i)
            	cin>>marks[i];
         }

      void update()
      	{
         	cout<<"GRno = "<<rno;
            cout<<"\nName = "<<name;
            cout<<"\nMarks in 5 subjects ";
            cout<<"\n";
            for(i=0;i<5;++i)
            	{
               	cout<<marks[i];
               	cout<<endl;
               }

            calculate();
            cout<<"Total = ";
            cout<<total;
         }


   };

void main()
	{
      clrscr();
   	STUDENT s;
      s.readinfo();
      s.update();
      getch();
   }