#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<process.h>

double power(int a , int n)
{
 return pow(a,n);
}

double power(double a , int n)
{
 double p=1;
 int i;
 for(i=0;i<n;++i)
 		p*=a;
 return p;
}


void main()
{
 clrscr();
 int n,ans,x1,n1,n2;
 char resp;
 double x2;
 double a;

 do

 {

 cout<<"\t\tMENU\n";
 cout<<"1. x and n are integers\n\n";
 cout<<"2. x is a decimal and n is an integer\n\n";
 cout<<"3. Exit\n\n";
 cout<<"Select an option (1/2/3) : ";
 cin>>ans;

 switch(ans)
 		{
       	case 1 : cout<<"Enter value of x = ";
         			cin>>x1;
         			cout<<"\nEnter value of n = ";
         			cin>>n1;
         			cout<<"x to the power n = "<<power(x1,n1) ;
                  break;
         case 2 : cout<<"Enter value of x = ";
         			cin>>x2;
                  cout<<"\nEnter value of n = ";
                  cin>>n2;
                  cout<<"x to the power n = "<<power(x2,n2);
                  break;
         case 3 : exit(0);
         			break;
         default : cout<<"Enter a valid answer!!!";
      }


 cout<<"\n\nDo you want to continue?? ";
 cin>>resp;

 }	while(resp=='y'||resp=='Y');
 getch();
}
