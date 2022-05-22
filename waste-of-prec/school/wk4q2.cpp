#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

class STUDENT
	{
   	char Name[20];
      int Rollno;

      protected :

      int Class;

      public :

      STUDENT()
      	{
         	strcpy(Name,"Not Assigned");
            Rollno = 0;
            Class = 0;
         }

      void Input();
      void Display();
   };

void STUDENT :: Input()
	{
   	cout<<"\nEnter Name of the student : ";
      gets(Name);
      cout<<"Enter Rollno : ";
      cin>>Rollno;
      cout<<"Enter Class : ";
      cin>>Class;
   }

void STUDENT :: Display()
	{
   	cout<<"\nStudent Details\n\n";
      cout<<"Name : "<<Name<<endl;
      cout<<"Rollno : "<<Rollno<<endl;
      cout<<"Class : "<<Class<<endl;
   }

class TEST : public STUDENT
	{
    	float English, Maths, Physics, Chemistry, ComputerScience;
      float Calculate_Total()
      	{
         	TotalMarks = English + Maths + Physics + Chemistry + ComputerScience;
         }

      protected :

      float TotalMarks;

      public :

      TEST()
      	{
         	English = 0;
            Maths = 0;
            Physics = 0;
            Chemistry = 0;
            ComputerScience = 0;
         }

      void getData()
      	{
          	cout<<"\nEnter Marks in the following subjects : \n\n";
            cout<<"English : ";
            cin>>English;
            cout<<"Maths : ";
            cin>>Maths;
            cout<<"Physics : ";
            cin>>Physics;
            cout<<"Chemistry : ";
            cin>>Chemistry;
            cout<<"Computer Science : ";
            cin>>ComputerScience;
            Calculate_Total();
         }

      void displayData()
      	{
         	cout<<"\nMarks of the student : \n\n";
            cout<<"English "<<English;
            cout<<"\nMaths "<<Maths;
            cout<<"\nPhysics "<<Physics;
            cout<<"\nChemistry "<<Chemistry;
            cout<<"\nComputer Science"<<ComputerScience;
         }


   };

class RESULT :: public TEST
	{
    	float Percentage;
      char Grade[20];

      public :

      RESULT()
      	{
         	Percentage = 0;
            strcpy(Grade,"E");
         }

      void calcPercentage()
      	{
          	cout<<"\nEnter Percentage : ";
            cin>>Percentage;
         }

      void calcGrade()
      	{
          	if(Percentage>=90)
            	strcpy(Grade,"A");
            else if(Percentage<90 && Percentage>=75)
            	strcpy(Grade,"B");
            else if(Percentage<75 && Percentage>=60)
            	strcpy(Grade,"C");
            else if(Percentage<60 && Percentage>=40)
            	strcpy(Grade,"D");
            else if(Percentage<40)                              //Inputed the condition as it is specified in question and Percentage entered could be more than 100 (mistake)
            	strcpy(Grade,"E");                              //Line of code not needed as the default os already E Grade
         }

      void displayResult()
      	{
            cout<<"\nResults of the Student :\n"
         	cout<<"\nPercentage "<<Percentage<<endl;
            cout<<"Grade "<<Grade;
         }
   };



void main()
	{
   	RESULT R;
      
   }











