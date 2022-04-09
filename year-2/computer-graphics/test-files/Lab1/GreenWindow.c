#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void init()
{
    glClearColor(0.0, 1.0, 0.0, 1.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Green window Arjav Jain 500083556");
    glutDisplayFunc(display);
    init();
    glutMainLoop();

    return 0;
}