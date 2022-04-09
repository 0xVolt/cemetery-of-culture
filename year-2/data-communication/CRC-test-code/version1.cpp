#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
 
void main()
{
    int i,j,k,l;
    
    //Get Frame
    int fs;
    cout<<"\n Enter Frame size: ";
    cin>>fs;
     
    int f[20];
     
    cout<<"\n Enter Frame:";
    for(i=0;i<fs;i++)
    {
        cin>>f[i];
    }
 
    //Get Generator
    int gs;
    cout<<"\n Enter Generator size: ";
    cin>>gs;
     
    int g[20];
     
    cout<<"\n Enter Generator:";
    for(i=0;i<gs;i++)
    {
        cin>>g[i];
    }
 
    cout<<"\n Sender Side:";
    cout<<"\n Frame: ";
    for(i=0;i<fs;i++)
    {
        cout<<f[i];
    }
    cout<<"\n Generator :";
    for(i=0;i<gs;i++)
    {
        cout<<g[i];
    }
 
    //Append 0's
    int rs=gs-1;
    cout<<"\n Number of 0's to be appended: "<<rs;
    for (i=fs;i<fs+rs;i++)
    {
        f[i]=0;
    }
 
    int temp[20];
    for(i=0;i<20;i++)
    {
        temp[i]=f[i];
    }
 
    cout<<"\n Message after appending 0's :";
    for(i=0; i<fs+rs;i++)
    {
        cout<<temp[i];
    }
 
    //Division
    for(i=0;i<fs;i++)
    {
        j=0;
        k=i;
        //check whether it is divisible or not
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
 
    //CRC
    int crc[15];
    for(i=0,j=fs;i<rs;i++,j++)
    {
        crc[i]=temp[j];
    }
 
    cout<<"\n CRC bits: ";
    for(i=0;i<rs;i++)
    {
        cout<<crc[i];
    }
 
    cout<<"\n Transmitted Frame: ";
    int tf[15];
    for(i=0;i<fs;i++)
    {
        tf[i]=f[i];
    }
    for(i=fs,j=0;i<fs+rs;i++,j++)
    {
        tf[i]=crc[j];
    }
    for(i=0;i<fs+rs;i++)
    {
        cout<<tf[i];
    }
 
    cout<<"\n Receiver side : ";
    cout<<"\n Received Frame: ";
    for(i=0;i<fs+rs;i++)
    {
        cout<<tf[i];
    }
 
    for(i=0;i<fs+rs;i++)
    {
        temp[i]=tf[i];
    }
 
    //Division
    for(i=0;i<fs+rs;i++)
    {
        j=0;
        k=i;
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
 
    cout<<"\n Remainder: ";
    int rrem[15];
    for (i=fs,j=0;i<fs+rs;i++,j++)
    {
        rrem[j]= temp[i];
    }
    for(i=0;i<rs;i++)
    {
        cout<<rrem[i];
    }
 
    int flag=0;
    for(i=0;i<rs;i++)
    {
        if(rrem[i]!=0)
        {
            flag=1;
        }
    }
 
    if(flag==0)
    {
        cout<<"\n Since Remainder Is 0 Hence Message Transmitted From Sender To Receriver Is Correct";
    }
    else
    {
        cout<<"\n Since Remainder Is Not 0 Hence Message Transmitted From Sender To Receriver Contains Error";
    }
    getch();
}
 
/* OUTPUT
 
 
 Enter Frame size: 6
 
 Enter Frame:1
0
0
1
0
0
 
 Enter Generator size: 4
 
 Enter Generator:1
1
0
1
 
 Sender Side:
 Frame: 100100
 Generator :1101
 Number of 0's to be appended: 3
 Message after appending 0's :100100000
 CRC bits: 001
 Transmitted Frame: 100100001
 Receiver side :
 Received Frame: 100100001
 Remainder: 000
 Since Remainder Is 0 Hence Message Transmitted From Sender To Receriver Is Corr
ect
 
*/