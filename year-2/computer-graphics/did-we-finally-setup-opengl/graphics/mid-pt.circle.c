// Code by Ananya Aditi Singh
// SAP Id: 500083972

#include <stdio.h>
#include <graphics.h>

void circlemidpoint(int,int,int);
void drawcircle(int,int,int,int);

int main() {
    int xc,yc,r;
    int gd=DETECT,gm;
    printf("Enter center coordinate of circle (x, y): ");
    // cin>>xc>>yc;
    scanf("%d %d", &xc, &yc);
    printf("Enter radius of circle: ");
    // cin>>r;
    scanf("%d", &r);
    initgraph(&gd,&gm,"");
    circlemidpoint(xc,yc,r);
    getch();
    closegraph();
    return 0;
}

void circlemidpoint(int xc,int yc,int r) {
    int x=0,y=r;
    int p=5/4-r;
    while(x<y)
    {
        drawcircle(xc,yc,x,y);
        x++;
        if(p<0) {
            p=p+2*x+1;
        } else {
            y--;
            p=p+2*(x-y)+1;
        }
        drawcircle(xc,yc,x,y);
    }
}

void drawcircle(int xc,int yc,int x,int y) {
    putpixel(xc+x, yc+y, WHITE);
    putpixel(xc-x, yc+y, WHITE);
    putpixel(xc+x, yc-y, WHITE);
    putpixel(xc-x, yc-y, WHITE);
    putpixel(xc+y, yc+x, WHITE);
    putpixel(xc-y, yc+x, WHITE);
    putpixel(xc+y, yc-x, WHITE);
    putpixel(xc-y, yc-x, WHITE);
}