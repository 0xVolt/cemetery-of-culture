#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float x2, y2, x3, y3, tx, ty;

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
    glVertex2f(x2+tx, y2+ty);
    glVertex2f(x3+tx, y3+ty);

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
    printf("Enter Translation value of X : ");
    scanf("%f",&tx);
    printf("Enter Translation value of Y : ");
    scanf("%f",&ty);

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
    gluOrtho2D(0,200,0,200);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(Translationlinedisplay);
    glutMainLoop();
}
