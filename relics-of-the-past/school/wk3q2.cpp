#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

class SPORTS
	{
   	char Name[20];
      char Team[20];
      long int Runscored;
      int Matches;

      public :

      SPORTS()
      	{
            Runscored = 25678;
            Matches = 150;
            strcpy(Name , "Dhoni");
            strcpy(Team , "India");
         }

      SPORTS(long int r)
      	{
         	r = Runscored;
            Matches = 200;
            strcpy(Name , "Suresh Raina");
            strcpy(Team , "India");
         }

      SPORTS(SPORTS&S)
      	{
         	strcpy(Name , S.Name);
            strcpy(Team , S.Team);
            Runscored = S.Runscored;
            Matches = S.Matches;
         }

      void Chkmatches()
      	{
            if (Matches > 50)
            	puts(Name);
         }

		void Displaydetails()
      	{
         	cout<<Runscored<<'\n';
            cout<<Matches<<'\n';
            puts(Name);
            cout<<"\n";
            puts(Team);
         }

      ~SPORTS()
      	{cout<<"Destroying Object...........";
         }
   };


void main()
	{
      clrscr();

    	SPORTS s1 , s2(700) , s3(s1);

      s1.Displaydetails();
      s2.Displaydetails();
      s3.Displaydetails();
      s1.Chkmatches();
      s2.Chkmatches();
      s3.Chkmatches();

      getch();
   }
