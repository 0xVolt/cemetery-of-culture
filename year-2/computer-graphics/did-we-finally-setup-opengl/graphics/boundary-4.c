// Code by Ananya Aditi Singh
// SAP Id: 500083972

#include <graphics.h>
void boundaryFill4(int x, int y, int fill_color, int boundary_color)
{
    if (getpixel(x, y) != boundary_color &&
        getpixel(x, y) != fill_color)
    {
        putpixel(x, y, fill_color);
        boundaryFill4(x + 1, y, fill_color, boundary_color);
        boundaryFill4(x, y + 1, fill_color, boundary_color);
        boundaryFill4(x - 1, y, fill_color, boundary_color);
        boundaryFill4(x, y - 1, fill_color, boundary_color);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int x = 500, y = 500, radius = 200;
    circle(x, y, radius);
    boundaryFill4(x, y, 6, 15);
    closegraph();
    getch();
    return 0;
}

