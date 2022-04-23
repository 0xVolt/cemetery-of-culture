#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

using namespace std;

/*void delay(float ms){
    clock_t goal = ms + clock();
    while(goal>clock());
}*/

float color[] = {1, 1, 1};
float boundColor[] = {1, 1, 1};
int choice;

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 200, 0, 150);
}

void flood(int x, int y, float *fill, float *ic)
{
    if ((x < 0) || (x >= 200))
        return;
    if ((y < 0) || (y >= 150))
        return;
    float col[3];
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, col);
    if (col[0] == ic[0] && col[1] == ic[1] && col[2] == ic[2])
    {
        glColor3f(fill[0], fill[1], fill[2]);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();
        glReadPixels(x - 1, y, 1.0, 1.0, GL_RGB, GL_FLOAT, col);
        if (col[0] == ic[0] && col[1] == ic[1] && col[2] == ic[2])
            flood(x - 1, y, fill, ic);
        glReadPixels(x + 1, y, 1.0, 1.0, GL_RGB, GL_FLOAT, col);
        if (col[0] == ic[0] && col[1] == ic[1] && col[2] == ic[2])
            flood(x + 1, y, fill, ic);
        glReadPixels(x, y + 1, 1.0, 1.0, GL_RGB, GL_FLOAT, col);
        if (col[0] == ic[0] && col[1] == ic[1] && col[2] == ic[2])
            flood(x, y + 1, fill, ic);
        glReadPixels(x, y - 1, 1.0, 1.0, GL_RGB, GL_FLOAT, col);
        if (col[0] == ic[0] && col[1] == ic[1] && col[2] == ic[2])
            flood(x, y - 1, fill, ic);
    }
    return;
}

void bound(int x, int y, float fillColor[3], float borderColor[3])
{
    if ((x < 0) || (x >= 200))
        return;
    if ((y < 0) || (y >= 150))
        return;
    float interiorColor[3];
    // getPixel(x,y,interiorColor);
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, interiorColor);
    if ((interiorColor[0] != borderColor[0] || (interiorColor[1]) != borderColor[1] || (interiorColor[2]) != borderColor[2]) && (interiorColor[0] != fillColor[0] || (interiorColor[1]) != fillColor[1] || (interiorColor[2]) != fillColor[2]))
    {
        // setPixel(x,y,fillColor);
        glColor3f(fillColor[0], fillColor[1], fillColor[2]);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();
        glReadPixels(x - 1, y, 1.0, 1.0, GL_RGB, GL_FLOAT, interiorColor);
        if ((interiorColor[0] != borderColor[0] || (interiorColor[1]) != borderColor[1] || (interiorColor[2]) != borderColor[2]) && (interiorColor[0] != fillColor[0] || (interiorColor[1]) != fillColor[1] || (interiorColor[2]) != fillColor[2]))
            bound(x - 1, y, fillColor, borderColor);
        glReadPixels(x + 1, y, 1.0, 1.0, GL_RGB, GL_FLOAT, interiorColor);
        if ((interiorColor[0] != borderColor[0] || (interiorColor[1]) != borderColor[1] || (interiorColor[2]) != borderColor[2]) && (interiorColor[0] != fillColor[0] || (interiorColor[1]) != fillColor[1] || (interiorColor[2]) != fillColor[2]))
            bound(x + 1, y, fillColor, borderColor);
        glReadPixels(x, y + 1, 1.0, 1.0, GL_RGB, GL_FLOAT, interiorColor);
        if ((interiorColor[0] != borderColor[0] || (interiorColor[1]) != borderColor[1] || (interiorColor[2]) != borderColor[2]) && (interiorColor[0] != fillColor[0] || (interiorColor[1]) != fillColor[1] || (interiorColor[2]) != fillColor[2]))
            bound(x, y + 1, fillColor, borderColor);
        glReadPixels(x, y - 1, 1.0, 1.0, GL_RGB, GL_FLOAT, interiorColor);
        if ((interiorColor[0] != borderColor[0] || (interiorColor[1]) != borderColor[1] || (interiorColor[2]) != borderColor[2]) && (interiorColor[0] != fillColor[0] || (interiorColor[1]) != fillColor[1] || (interiorColor[2]) != fillColor[2]))
            bound(x, y - 1, fillColor, borderColor);
    }
}

void keyPressed(unsigned char key, int x, int y)
{
    if (key == 'b')
    {
        choice = 1;
    }
    else
    {
        choice = 2;
    }
}

void mouse(int btn, int state, int x, int y)
{
    y = 150 - y;
    if (btn == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            if (choice == 1)
            {
                glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, boundColor);
                choice = 1;
            }
            else
            {
                glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color);
                choice = 2;
            }

            // clicks++;
        }
    }

    if (btn == GLUT_RIGHT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            float intCol[] = {0, 0, 0};
            glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, intCol);
            if (color[0] != intCol[0] || color[1] != intCol[1] || color[2] != intCol[2])
            {
                if (choice == 1)
                {
                    bound(x, y, color, boundColor);
                    choice = 1;
                }
                else
                {
                    flood(x, y, color, intCol);
                    choice = 2;
                }

                // clicks = 0;
            }
        }
    }
}

void display()
{
    // glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(50, 0);
    glVertex2i(150, 0);
    glVertex2i(150, 50);
    glVertex2i(50, 50);
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(50, 150);
    glVertex2i(150, 150);
    glVertex2i(150, 100);
    glVertex2i(50, 100);
    glEnd();
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(50, 50);
    glVertex2i(0, 50);
    glVertex2i(0, 0);
    glVertex2i(50, 0);
    glEnd();
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(200, 0);
    glVertex2i(150, 0);
    glVertex2i(150, 50);
    glVertex2i(200, 50);
    glEnd();
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(200, 150);
    glVertex2i(150, 150);
    glVertex2i(150, 100);
    glVertex2i(200, 100);
    glEnd();
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(50, 100);
    glVertex2i(0, 100);
    glVertex2i(0, 150);
    glVertex2i(50, 150);
    glEnd();
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(50, 100);
    glVertex2i(0, 100);
    glVertex2i(0, 50);
    glVertex2i(50, 50);
    glEnd();
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(200, 100);
    glVertex2i(150, 100);
    glVertex2i(150, 50);
    glVertex2i(200, 50);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(200, 150);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Flood Fill Algo");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyPressed);
    glutMouseFunc(mouse);
    // init();
    glutMainLoop();
    return 0;
}