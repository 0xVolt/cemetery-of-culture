#include<iostream.h>
#include<conio.h>         
#include<process.h>

double sum(int a , int b)
{
	return a+b;
}

double sum(float a[100] , int b)
{
	int s=0,i;
   for(i=0;i<=b;++i)
   	{
       	s+=a[i];
      }
   return s;
}

double sum(int a[100] , int b , char c)
{
	int i,s=0;
   if(c=='e'||c=='E')
   	{
      	for(i=0;i<b;++i)
         	{
            	if(a[i]%2==0)
               	s+=a[i];
            }
      }
   else if(c=='o'||c=='O')
   	{
      	for(i=0;i<b;++i)
         	{
            	if(a[i]%2!=0)
               	{
                  	s+=a[i];
                  }
            }
      }
   return s;
}

void main()
{
   clrscr();

   int choice,x,y,n,i,a1[100];
   float a[100];
   char ans,c;

   do
   	{

   cout<<"\n\n1. Sum of two integers ";
   cout<<"\n2. Sum of multiple integers";
   cout<<"\n3. Sum of Even / Odd numbers in an array";
   cout<<"\n4.Exit";
   cout<<"\n\nSelect a number (1/2/3/4) = ";
   cin>>choice;

   switch(choice)
   	{
       	case 1 : cout<<"Enter two integers = ";
         			cin>>x>>y;
                  cout<<"Sum of two integers = "<<sum(x,y);
                  break;

         case 2 : cout<<"How many numbers = ";
         			cin>>n;
                  cout<<"Enter the numbers = ";
                  for(i=0;i<n;++i)
                  	{
                     	cin>>a[i];
                     }
                  cout<<"Sum of the numbers = "<<sum(a,n);
                  break;

         case 3 :	cout<<"How many numbers : ";
         			cin>>n;
                  cout<<"Enter numbers : \n";
                  for(i=0;i<n;++i)
                  	cin>>a1[i];
                  cout<<"Even or Odd numbers ? (E/O) : ";
                  cin>>c;
                  cout<<"Sum of Numbers = "<<sum(a1,n,c);
                  break;

         case 4 : exit(0);

         default : cout<<"Invalid choice!!!";
   	}
   cout<<"\n\nDo you want to continue ? (Y/N) : ";
   cin>>ans;
   }while(ans=='y'||ans=='Y');
   getch();
}
