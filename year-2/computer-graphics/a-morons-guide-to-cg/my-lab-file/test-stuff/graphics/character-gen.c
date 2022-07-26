#include<stdio.h>  
#include<graphics.h> 
void main()  
{     
    int gd=DETECT,gm;  
    initgraph(&gd,&gm,"");  
    setbkcolor(9);  
    line(100,100,370,100);  
      
    line(120,100,120,170);  
    arc(143,100,0,180,23);  
    line(165,100,165,155);  
    arc(150,155,100,0,15);  
    line(180,100,180,170);  
  
    circle(210,140,10);  
    line(210,130,250,130);  
  
    circle(280,140,10);  
    line(280,130,330,130);  
    line(330,100,330,170);  
    line(345,100,345,170);  
    ellipse(337,100,0,180,9,18);  
    getch();  
}  