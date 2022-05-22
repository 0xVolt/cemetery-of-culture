#include<fstream.h>
#include<conio.h>

void COUNT_DO()
	{
   	ifstream f1;
      f1.open("MEMO.txt");
      char Word[20];
      int count = 0;
      while(f1>>Word)
      	{
         	if(strcmp(Word,"do")==0)
            	count++;
         }
      cout<<"Count of the given Word in the file = "<<count;
      f1.close();
   }

void main()
	{
   	clrscr();
      COUNT_DO();
      getch();
   }