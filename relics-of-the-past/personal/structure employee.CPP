#include<iostream.h>
#include<conio.h>
#include<stdio.h>
struct employee
{
 int empno;
 char name[23];
 char dept[23];
 char desig[45];
 float salary;
};
void main()
{
 int i,t;
 employee e[5];
 for(i=0;i<5;++i)
 	{
    cout<<"Enter employee number = ";
    cin>>e[i].empno;
    cout<<"Enter employee name = ";
    gets(e[i].name);
    cout<<"Enter department = ";
    gets(e[i].dept);
    cout<<"Enter employee designation = ";
    gets(e[i].desig);
    cout<<"Enter employee's salary = ";
    cin>>e[i].salary;

    cout<<"Employee number = "<<e[i].empno<<"\nEmployee name = "<<e[i].name<<"\nDepartment = "<<e[i].dept<<"\nDesignation = "<<e[i].desig<<"\nEmployee salary = "<<e[i].salary;
	}

 for(i=0;i<4;++i)
 	{
    if(e[i].salary>e[i+1].salary)
    	{
       int t;
       t=e[i].salary;
       e[i].salary=e[i+1].salary;
       e[i+1].salary=t;
      }
   }

 cout<<"Sorted List \n";
 for(i=0;i<5;++i)
 	{
    cout<<"Employee "<<i+1<<"\n\tSalary = "<<e[i].salary;
   }
}
