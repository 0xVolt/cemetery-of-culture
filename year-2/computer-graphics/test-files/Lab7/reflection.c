#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float x1, y3, x2, y2;
float m, c, p, q;
int Round(double a)
{
    if (a - (int)(a) >= 0.5)
    {
        return (int)(a) + 1;
    }
    else
    {
        return (int)(a);
    }
}
void myInit()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}
void draw_pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
void draw_line(double x1, double x2, double y1, double y2)
{
    int dx, dy, i, e;
    int incx, incy, inc1, inc2;
    int x, y;
    int xx2 = Round(x2);
    int xx1 = Round(x1);
    int yy1 = Round(y1);
    int yy2 = Round(y2);
    dx = Round(x2) - Round(x1);
    dy = Round(y2) - Round(y1);
    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    incx = 1;
    if (xx2 < xx1)
        incx = -1;
    incy = 1;
    if (yy2 < yy1)
        incy = -1;
    x = xx1;
    y = yy1;
    if (dx > dy)
    {
        draw_pixel(x, y);
        e = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;
        for (i = 0; i < dx; i++)
        {
            if (e >= 0)
            {
                y += incy;
                e += inc1;
            }
            else
                e += inc2;
            x += incx;
            draw_pixel(x, y);
        }
    }
    else
    {
        draw_pixel(x, y);
        e = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;
        for (i = 0; i < dy; i++)
        {
            if (e >= 0)
            {
                x += incx;
                e += inc1;
            }
            else
                e += inc2;
            y += incy;
            draw_pixel(x, y);
        }
    }
}
void myDisplay()
{
    draw_pixel(p, q);
    draw_line(x1, x2, y3, y2);
    double p1, q1;
    p1 = ((1 - m * m) * p + 2 * m * q - 2 * c * m) / (1 + m * m);
    q1 = (2 * m * p + (m * m - 1) * q + 2 * c) / (1 + m * m);
    draw_pixel(p1, q1);
    glFlush();
}
int main(int argc, char **argv)
{
    printf("Enter m ,c of y=mx+c: ");
    scanf("%f %f", &m, &c);
    x1 = 0;
    y3 = c;
    if (m == 0)
    {
        y2 = c;
        x2 = 500;
    }
    else
    {
        x2 = (500 - c) / m;
        y2 = 500;
    }
    printf("Enter the point p to reflect: ");
    scanf("%f %f", &p, &q);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Point Reflection");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}