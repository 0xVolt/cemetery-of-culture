#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float x2, y2, x3, y3, r;

void Translationlinedisplay()
{
    glClearColor(1, 1, 1, 0);
    glColor3f(1, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glColor3f(0, 1, 0);
    glVertex2f(((x2*cos(r))-(y2*sin(r))),((x2*sin(r))+(y2*cos(r))));
    glVertex2f(((x3*cos(r))-(y3*sin(r))),((x3*sin(r))+(y3*cos(r))));

    glEnd();
    glFlush();

}

int main(int argc, char** argv)
{
    //origin is 0,0
    printf("Enter the value of x1 : ");
    scanf("%f",&x2);
    printf("Enter the value of y1 : ");
    scanf("%f",&y2);
    printf("Enter the value of x2 : ");
    scanf("%f",&x3);
    printf("Enter the value of y2 : ");
    scanf("%f",&y3);
    printf("Enter Rotation angle : ");
    scanf("%f",&r);
    r=r*11/630;
    printf("%f %f", sin(r), cos(r));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(80, 54);
    glutCreateWindow("2D Translation");

    printf("\n Red indicates old 2D shape");
    printf("\n Green indicates New 2D shape");

    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glPointSize(4);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(Translationlinedisplay);
    glutMainLoop();
}
