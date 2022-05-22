#include<iostream.h>
#include<conio.h>
void main()
{
 clrscr();
 int i,a[100][100],b[100][100],c[100][100],k,p,q,m,n,j;
 cout<<"Enter number of rows and columns for Matrix A\n";
 cin>>m>>n;
 cout<<"\nEnter number of rows and columns for Matrix B\n";
 cin>>p>>q;
 if(n!=p)
 	cout<<"\n\nProcess TERMINATED";
 else
 	{
    cout<<"\nEnter elements of Matrix A\n";
    for(i=0;i<m;++i)
    	for(j=0;j<n;++j)
      	cin>>a[i][j];
    cout<<"\nEnter elements of Matrix B\n";
    for(i=0;i<p;++i)
    	for(j=0;j<q;++j)
         cin>>b[i][j];
    cout<<"\n\nMatrix A\n";
    for(i=0;i<m;++i)
    	{
       for(j=0;j<n;++j)
       	cout<<a[i][j]<<"  ";
       cout<<endl;
      }
    cout<<"\nMatrix B\n";
    for(i=0;i<p;++i)
    	{
       for(j=0;j<q;++j)
       	cout<<b[i][j]<<"  ";
       cout<<endl;
		}

    cout<<"\n\nProduct of Matrices\n";
    for(i=0;i<m;++i)
    	for(j=0;j<p;++j)
      	{
          c[i][j]=0;
          for(k=0;k<n;++k)
          	c[i][j]+=a[i][k]*b[k][j];
         }
    for(i=0;i<m;++i)
    	{for(j=0;j<n;++j)
      	cout<<c[i][j]<<"  ";
      cout<<endl;
       }
   }
 getch();
}