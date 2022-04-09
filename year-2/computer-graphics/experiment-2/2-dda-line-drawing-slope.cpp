// Code by Desh Iyer

// PROBLEM STATEMENT
// Draw a line using the DDA line drawing algorithm

// CODE
// Include libraries
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

float x1,x2,y1,y2;

void display(void) {
    float dy,dx,step,x,y,k,Xin,Yin;

    dx=x2-x1;
    dy=y2-y1;

    if(abs(dx) > abs(dy)) {
        step = abs(dx);
    } else
        step = abs(dy);

    Xin = dx/step;
    Yin = dy/step;
    x= x1;
    y=y1;

    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_LINES);
    glVertex2i(-20,0);
    glVertex2i(20,0);
    glEnd();

    glColor3f(1.0,0.0,0.0);

    glBegin(GL_LINES);
    glVertex2i(0,-20);
    glVertex2i(0,20);
    glEnd();

    glColor3f(1.0,0.0,0.0);

    glBegin(GL_LINES);
    glVertex2i(x,y);

    for (k=1 ;k<=step;k++) {
        x= x + Xin;
        y= y + Yin;
    }

    glVertex2i(x,y);
    glEnd();
    glFlush();
}

void init(void) {
    glClearColor(0.7,0.7,0.7,0.7);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20,20,-20,20);
}

int main(int argc, char** argv) {
    printf("Enter the value of x1 : ");
    scanf("%f",&x1);

    printf("Enter the value of y1 : ");
    scanf("%f",&y1);

    printf("Enter the value of x2 : ");
    scanf("%f",&x2);

    printf("Enter the value of y2 : ");
    scanf("%f",&y2);

    glutInit(&argc, argv);

    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100,100);
    glutCreateWindow ("Desh Iyer(500081889)-> DDA Line Algo");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}