#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float x2, y2, x3, y3;

void linedisplay()
{
   glClearColor(1, 1, 1, 0);
   glColor3f(1, 0, 0);
   glClear(GL_COLOR_BUFFER_BIT);

   float m = (y3 - y2) / (x3 - x2), c = y2 - m * x2, y;

   glBegin(GL_POINTS);
   for (float x = 0; x <= 200; x = x + 1)
   {
       y = x;
       glColor3f(0.9, 0.9,0.9);
       glVertex2f(x, y);
   }
   for (float x = x2; x <= x3; x = x + 1)
   {
       y = m * x + c;
       glColor3f(1, 0, 0);
       glVertex2f(x, y);
       glColor3f(0, 1, 0);
       glVertex2f(y, x);
   }

   glEnd();
   glFlush();

}

int main(int argc, char** argv)
{
    printf("Enter the value of x1 : ");
    scanf("%f",&x2);
    printf("Enter the value of y1 : ");
    scanf("%f",&y2);
    printf("Enter the value of x2 : ");
    scanf("%f",&x3);
    printf("Enter the value of y2 : ");
    scanf("%f",&y3);

    printf("\n Red indicates old 2D shape");
    printf("\n Green indicates New 2D shape");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(80, 54);
    glutCreateWindow("Line ALGO");

    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glPointSize(4);
    glLoadIdentity();
    gluOrtho2D(0,200,0,200);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(linedisplay);
    glutMainLoop();
}
