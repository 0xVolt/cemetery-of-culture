
/*

MENU DRIVEN PROGRAM TO CALCULATE
AREA OF SQUARE, RECTANGLE AND CIRCLE. PERFECT EXAMPLE OF SWITCH
CASE

*/



#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<math.h>

void main()
	{
   	int ans;
      float l,b,r;
      char resp;
      do
      	{
         	cout<<"\n\n --------M E N U--------\n";
            cout<<"\n1 . Area of a Square\n";
            cout<<"2 . Area of a rectangle\n";
            cout<<"3 . Area of a Circle\n";
            cout<<"4 . Exit\n\n";
            cout<<"Enter your choice (1/2/3/4) = ";
            cin>>ans;
            switch(ans)
            	{
               	case 1 : cout<<"Enter side length = ";
                  			cin>>l;
                           cout<<"Area = "<<pow(l,2);
                           break;

                  case 2 : cout<<"Enter length = ";
                  			cin>>l;
                           cout<<"Enter breadth = ";
                           cin>>b;
                           cout<<"Area = "<<l*b;
                           break;

                  case 3 : cout<<"Enter radius of the circle = ";
                  			cin>>r;
                           cout<<"Area = "<<3.14159*pow(r,2);
                           break;

                  case 4 : exit(0);

                  default : cout<<"Wrong Choice\nPlease try again\n";
               }
            cout<<"\nDo you want to continue?\n";
            cout<<"(Y : Yes || N : No)\n";
            cin>>resp;
         }
      while(resp=='y'||resp=='Y');
   }