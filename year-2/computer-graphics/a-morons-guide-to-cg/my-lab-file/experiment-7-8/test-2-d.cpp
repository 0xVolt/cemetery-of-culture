#include <iostream>
#include <GL/glut.h>
using namespace std;

// Declaring global variables
float x1, x2, y1, y2, xOffset, yOffset;
char option;

// Function prototypes
void displayTranslate();
void inputVariables();

int main(int argc, char **argv) {
    inputVariables();

    // Inits glut
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    // Window dimensions and position
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(80, 54);

    // Create the window to display graphics
    glutCreateWindow("2D Transformations");

    // Set background 
    glClearColor(1, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
    
    // Point size
    glPointSize(4);
    glLoadIdentity();

    // Make a set of points for 2D
    gluOrtho2D(0,200,0,200);

    // Configure how hte model is viewed
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(displayTranslate);
    glutMainLoop();

    return 0;
}

void displayTranslate() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);

    glColor3f(0, 0, 0);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);

    glColor3f(255, 0, 102);
    glVertex2f(x1 + xOffset, y1 + yOffset);
    glVertex2f(x2 + xOffset, y2 + yOffset);

    glEnd();
    glFlush();
}



void inputVariables() {
    cout << "Enter x1: ";
    cin >> x1;

    cout << "Enter y1: ";
    cin >> y1;

    cout << "Enter x2: ";
    cin >> x2;

    cout << "Enter y2: ";
    cin >> y2;

    cout << "\n\nInput value to offset x by: ";
    cin >> xOffset;

    cout << "Enter value to offset y by: ";
    cin >> yOffset;

    // cout << "\n\na. Translation";
    // cout << "\nb. Rotation";
    // cout << "\nc. Reflection about axis";
    // cout << "\nd. Reflection about line";
    // cout << "\ne. Shear edge about a vertex";

    // cout << "\n\nEnter an option: ";
    // cin >> option;
}