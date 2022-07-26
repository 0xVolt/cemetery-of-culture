#include<iostream.h>
#include<conio.h>
#include<stdio.h>

int i;

class EMPLOYEE
	{
    	int Empno;
      char Name[20];
      float Basicpay,HRA,DA,PF;
      double Netpay;

      public :

      void Getdata();
      double Compute();
      void Printdata();
   };

void EMPLOYEE :: Getdata()
	{
		cout<<"\n\nEnter Empno = ";
      cin>>Empno;
      cout<<"Enter Name = ";
      gets(Name);
      cout<<"Enter Basic Pay of the employee = ";
      cin>>Basicpay;
   }

double EMPLOYEE :: Compute()
	{
      float Npay;
   	HRA = 0.1 * Basicpay;
      DA = 0.5 * Basicpay;
      PF = 0.08 * Basicpay;
      Npay = Basicpay + HRA + DA - PF;
      return Npay;
   }

void EMPLOYEE :: Printdata()
	{
   	Netpay = Compute();
      cout<<"\nEmpno = "<<Empno;
      cout<<"\nName = "<<Name;
      cout<<"\nBasic Pay = "<<Basicpay;
      cout<<"\nHRA = "<<HRA;
      cout<<"\nDA = "<<DA;
      cout<<"\nPF = "<<PF;
      cout<<"\nNetpay = "<<Netpay;
   }

void main()
	{
   	clrscr();


      int n;
      EMPLOYEE emp1[20];
      cout<<"How many Employees : ";
      cin>>n;
      for(i=0;i<n;++i)
      	{
            cout<<"\nEnter details of employee "<<i+1;
      		emp1[i].Getdata();
         }
      for(i=0;i<n;++i)
      	{
          	cout<<"\n\nDetails of Employee "<<i+1;
            emp1[i].Printdata();
         }


      getch();
   }

