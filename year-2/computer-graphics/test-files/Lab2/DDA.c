#include <stdio.h>
#include <GL/glut.h>
void init()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("DDA Arjav Jain 500083556");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 100, 0, 100);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
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

    float m, dx, dy, x_inc, y_inc;
    dx = x2 - x1;
    dy = y2 - y1;
    m = dy / dx;

    int steps = (abs(dx) > abs(dy)) ? dx : dy;

    x_inc = dx / (float)steps;
    y_inc = dy / (float)steps;

    float x, y;

    x = x1;
    y = y1;
    glBegin(GL_POINTS);

    for (int i = 0; i < steps; i++)
    {
        glVertex2f(x, y);
        x += x_inc;
        y += y_inc;
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