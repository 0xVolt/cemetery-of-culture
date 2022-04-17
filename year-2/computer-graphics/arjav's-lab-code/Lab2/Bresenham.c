#include <stdio.h>
#include <GL/glut.h>
void init()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 200);

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
}

void display()
{
    glColor3f(0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    float x1, x2, y1, y2;

    printf("Enter x1:");
    scanf("%f", &x1);

    printf("Enter y1:");
    scanf("%f", &y1);

    printf("Enter x2:");
    scanf("%f", &x2);

    printf("Enter y2:");
    scanf("%f", &y2);

    int m, dx, dy, x_inc, y_inc, p;
    dx = x2 - x1;
    dy = y2 - y1;
    m = dy / dx;

    p = (2 * dy) - dx;
    glBegin(GL_POINTS);

    if (m < 1)
    {
        while (x1 < x2)
        {
            if (p > 0)
            {
                glVertex2i(x1, y1);
                y1 += 1;
                p = p + (2 * dy) - (2 * dx);
            }
            else
            {
                glVertex2i(x1, y1);
                p = p + (2 * dy);
            }
            x1 += 1;
        }
    }
    else
    {
        while (y1 < y2)
        {
            if (p > 0)
            {
                glVertex2i(x1, y1);
                x1 += 1;
                p = p + (2 * dx) - (2 * dy);
            }
            else
            {
                glVertex2i(x1, y1);
                p = p + (2 * dx);
            }
            y1 += 1;
        }
    }
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}