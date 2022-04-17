#include <graphics.h>
#include <stdio.h>
// #include <conio.h>
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    int getbkcolor();
    setbkcolor(BLUE);

    circle(200, 100, 30);
    circle(200, 100, 20);
    circle(200, 100, 10);

    circle(400, 100, 30);
    circle(400, 100, 20);
    circle(400, 100, 10);

    rectangle(300, 200, 310, 310);
    rectangle(200, 400, 400, 405);
    line(230, 405, 230, 420);
    line(260, 405, 260, 420);
    ellipse(245, 420, 180, 0, 15, 10);

    // filling colours

    setfillstyle(SOLID_FILL, BLUE);
    setfillstyle(SOLID_FILL, RED);
    floodfill(255, 419, WHITE);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(229, 129, WHITE);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(210, 110, WHITE);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(201, 101, WHITE);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(429, 129, WHITE);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(410, 110, WHITE);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(401, 101, WHITE);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(244, 403, WHITE);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(259, 450, WHITE);

    // delay(5000);
    getch();

    closegraph();
    return 0;
}