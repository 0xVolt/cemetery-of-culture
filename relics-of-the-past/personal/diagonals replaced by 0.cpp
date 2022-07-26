#include<iostream.h>
#include<conio.h>
void main() {
 clrscr();
 int a[10][10],i,j,m;
 cout<<"Enter m value for m*m matrix:\n";
 cin>>m;
 cout<<"Enter matrix:\n";
 for(i=0;i<m;++i)
 	for(j=0;j<m;++j)
   	cin>>a[i][j];
 cout<<"Modified Matrix:\n";
 for(i=0;i<m;++i) {
 	for(j=0;j<m;++j) {
    if(i==j||i+j==m-1)
    	cout<<0<<" ";
    else
    	cout<<a[i][j]<<" ";
   }
 cout<<endl;}
 getch();
 
}
