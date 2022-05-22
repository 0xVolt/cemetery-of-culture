 #include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

class RESTRA
	{
   	int foodcode;
      char food[20],  Ftype[20], sticker[20];
      void Getsticker();

      public :

      RESTRA()
      	{
          	foodcode = 0;
            strcpy(food,"\0");
            strcpy(Ftype,"\0");
            strcpy(sticker,"Green");
         }

      void Getfood();
      void Showfood();
   };

void RESTRA :: Getfood()
	{
   	cout<<"Enter foodcode = ";
      cin>>foodcode;
      cout<<"Enter food = ";
      gets(food);
      cout<<"Enter food type (Vegetarian / Contains Egg / Non Vegetarian) = ";
      gets(Ftype);
      Getsticker();
   }

void RESTRA :: Getsticker()
	{
   	if (strcmp(Ftype,"Vegetarian")==0||strcmp(Ftype,"vegetarian")==0)
      	strcpy(sticker,"Green");

      else if (strcmp(Ftype,"Contains Egg")==0||strcmp(Ftype,"egg")==0)
      	strcpy(sticker,"Yellow");

   	else if (strcmp(Ftype,"Non Vegetarian")==0||strcmp(Ftype,"nonveg")==0 )
      	strcpy(sticker,"Red");
   }

void RESTRA :: Showfood()
	{
   	cout<<"\nFoodcode : "<<foodcode;
      cout<<"\nFood : "<<food;
      cout<<"\nFood type : "<<Ftype;
      cout<<"\nSticker : "<<sticker;
   }

void main()
	{
      clrscr();

   	RESTRA f1;
      f1.Getfood();
      f1.Showfood();

      getch();
   }