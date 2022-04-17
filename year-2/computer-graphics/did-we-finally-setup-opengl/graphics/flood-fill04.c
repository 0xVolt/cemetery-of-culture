// Code by Ananya Aditi Singh
// SAP Id: 500083972

#include <stdio.h>
#include <graphics.h>
void flood(int, int, int, int);
void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    rectangle(50, 50, 250, 250);
    flood(55, 55, 10, 0);
    getch();
    closegraph();
}

void flood(int x, int y, int fillColor, int defaultColor)
{
    if (getpixel(x, y) == defaultColor)
    {
        putpixel(x, y, fillColor);
        flood(x + 1, y, fillColor, defaultColor);
        flood(x - 1, y, fillColor, defaultColor);
        flood(x, y + 1, fillColor, defaultColor);
        flood(x, y - 1, fillColor, defaultColor);
    }
}