#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

void Bresencircledisplay() {
    glClearColor(1, 1, 1, 0);
    glColor3f(0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    float r = 200, theta = 0;

    glBegin(GL_POINTS);

    while(theta <=360) {
        glVertex2f(r * cos(theta), r * sin(theta));
        theta+=1;
    }

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(800, 800);
   glutInitWindowPosition(80, 54);
   glutCreateWindow("Using Polar coordinates to draw a circle");

   glClearColor(0,0,0,0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-500,500,-500,500);
   glMatrixMode(GL_MODELVIEW);

   glutDisplayFunc(Bresencircledisplay);
   glutMainLoop();

   return 0;
}