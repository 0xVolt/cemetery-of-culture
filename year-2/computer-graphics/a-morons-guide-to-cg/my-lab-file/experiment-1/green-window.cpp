// Code by Desh Iyer

// PROBLEM STATEMENT
// Write a program with the help of OpenGL to initialize a window of green colour

// CODE
// Include libraries
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
using namespace std;

// Function to display the window
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

// Function to initialize the window
void init() {
    glClearColor(0.0, 1.0, 0.0, 1.0);
}

// Start of main() function
int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Displaying a Green window with OpenGL");

    glutDisplayFunc(display);
    init();

    glutMainLoop();

    return 0;
} // End of main() function
