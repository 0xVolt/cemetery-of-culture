#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float rx, ry;

void mpellipsedisplay()
{
    glClearColor(1, 1, 1, 0);
    glColor3f(0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    float xc = 0, yc = 0, dx, dy, x=0, y=ry, d1 = (ry*ry) - (rx*rx*ry) + (0.25*rx*rx);

    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    glBegin(GL_POINTS);

    while (dx < dy)
    {
        glVertex2f(x + xc, y + yc);
        glVertex2f(-x + xc, y + yc);
        glVertex2f(x + xc, -y + yc);
        glVertex2f(-x + xc, -y + yc);
        x++;
        if (d1 < 0)
        {
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }
    float d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5)))+ ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);
    while (y >= 0)
    {
        glVertex2f(x + xc, y + yc);
        glVertex2f(-x + xc, y + yc);
        glVertex2f(x + xc, -y + yc);
        glVertex2f(-x + xc, -y + yc);

        y--;
        if (d2 > 0)
        {
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    printf("Enter the value of x-axis radius: ");
    scanf("%f",&rx);
    printf("Enter the value of y-axis radius: ");
    scanf("%f",&ry);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(80, 54);
    glutCreateWindow("Mid-Point Circle ALGO");

    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(mpellipsedisplay);
    glutMainLoop();
}
