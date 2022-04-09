#include <stdio.h>
#include <GL/glut.h>

int xc;
int yc;
int r;
void init()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Midpoint Circle Arjav Jain 500083556");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-20, 20, -20, 20);
}
void putpixel(int x, int y)
{
    glPointSize(5.0);
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(x + xc, y + yc);
    glEnd();
}
void display()
{
    int x = 0;
    int y = r;
    float dec = 1 - r;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(-20, 0);
    glVertex2i(20, 0);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(0, -20);
    glVertex2i(0, 20);
    glEnd();

    putpixel(x, y);

    while (y > x)
    {
        if (dec < 0)
        {
            x++;
            dec += 2 * x + 1;
        }
        else
        {
            y--;
            x++;
            dec += 2 * (x - y) + 1;
        }
        putpixel(x, y);
        putpixel(x, -y);
        putpixel(-x, y);
        putpixel(-x, -y);
        putpixel(y, x);
        putpixel(-y, x);
        putpixel(y, -x);
        putpixel(-y, -x);
    }

    glFlush();
}
int main(int argc, char **argv)
{

    printf("Enter the coordinates of the circle's center:");
    scanf("%d %d", &xc, &yc);
    printf("Enter the radius of the circle:");
    scanf("%d", &r);
    glutInit(&argc, argv);
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}