#include<iostream.h>
#include<conio.h>
void main()
{
 char c;
 cout<<"Enter a letter\n";
 cin>>c;
 switch(c)
 {
  case 'a':
  case 'A':
  case 'e':
  case 'E':
  case 'I':
  case 'i':cout<<"Vowel!!";
  			  break;
  default :cout<<"Not a vowel!!";
 }
 getch();
}