// Code by Ananya Aditi Singh
// SAP Id: 500083972

#include <stdio.h>
#include <graphics.h>
#include <math.h>

void draw_line(float, float, float, float);
int roundFloat(float);

void main()
{

    int gdriver, gmode;
    float x1, y1, x2, y2;

    // clrscr();
    printf("Enter the two end - points of the line:");
    printf("nx1 =");
    scanf("%f", &x1);
    printf("y1 =");
    scanf("%f", &y1);
    printf("x2 =");
    scanf("%f", &x2);
    printf("y2 =");
    scanf("%f", &y2);

    gdriver = DETECT;
    initgraph(&gdriver, &gmode,"");
    draw_line(x1, y1, x2, y2);
    getch();
    closegraph();
}

void draw_line(float x1, float y1, float x2, float y2)
{
    float m, c, x, y;
    m = (y2 - y1) / (x2 - x1);
    c = y1 - m * x1;
    for (x = x1; x < x2; x++)
    {
        y = m * x + c;
        y = roundFloat(y);
        putpixel(x, (int)y, EGA_WHITE);
    }
}
int roundFloat(float x)
{
    int val = (x + 0.5);
    return (val);
}