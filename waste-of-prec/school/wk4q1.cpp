#include<iostream.h>
#include<conio.h>
#include<stdio.h>

class publication
	{
   	char title[20];
      float price;

      public :

      void getdata();
      void putdata();
   };

void publication :: getdata()
	{
   	cout<<"Enter Title : ";
      gets(title);
      cout<<"Enter Price : ";
      cin>>price;
   }

void publication :: putdata()
	{
      cout<<"\nTitle : "<<title<<endl;
   	cout<<"Price : "<<price<<endl;
   }

class book : public publication
	{
   	int pagecount;

      public :

   	void getdata()
      	{
            cout<<"Please Enter the details of a Book\n\n";

         	publication :: getdata();
            cout<<"Enter the Number of pages in the book : ";
            cin>>pagecount;
         }

      void putdata()
      	{
            cout<<"\n\nDetails of the Book entered\n\n";

         	publication :: putdata();
            cout<<"Number of pages in the book : "<<pagecount<<endl;
         }
   }B;

class tape : public publication
	{
   	float playtime;

      public :

      void getdata()
      	{

            cout<<"\n\nPlease enter details of the Audio Tape\n\n";

         	publication :: getdata();
            cout<<"Enter the Playing Time (Minutes) : ";
            cin>>playtime;
         }

      void putdata()
      	{
            cout<<"\n\nDetails of the Audio Tape entered \n\n";

            publication :: putdata();
         	cout<<"Playing Time (Minutes) : "<<playtime<<endl;
         }
   }C;

void main()
	{
      clrscr();

      B.getdata();
      C.getdata();

      B.putdata();
      C.putdata();

      getch();
   }