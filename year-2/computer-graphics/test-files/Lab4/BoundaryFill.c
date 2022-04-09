#include <stdio.h>
#include <GL/glut.h>
int x, y;
void init()
{
    gluOrtho2D(0, 500, 0, 500);
}
void boundaryFill(int x, int y, float ll[3], float boundary[3])
{
    float color[3];
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color);
    if ((color[0] != boundary[0] || color[1] != boundary[1] || color[2] != boundary[2]) && (color[0] != ll[0] || color[1] != ll[1] || color[2] != ll[2]))
    {
        glColor3f(ll[0], ll[1], ll[2]);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();
        boundaryFill(x + 1, y, ll, boundary);
        boundaryFill(x - 1, y, ll, boundary);
        boundaryFill(x, y + 1, ll, boundary);
        boundaryFill(x, y - 1, ll, boundary);
        boundaryFill(x - 1, y - 1, ll, boundary);
        boundaryFill(x + 1, y - 1, ll, boundary);
        boundaryFill(x + 1, y + 1, ll, boundary);
        boundaryFill(x - 1, y + 1, ll, boundary);
    }
}
void display()
{
    int n, a, b, i;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the vertices: ");
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        glVertex2f(a, b);
    }
    glEnd();
    glFlush();
    printf("Enter seed vertex: ");
    scanf("%d %d", &x, &y);
    float boundary[3] = {1.0f, 1.0f, 1.0f};
    float color[3] = {1.0f, 0.0f, 0.0f};
    boundaryFill(x, y, color, boundary);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Boundary Fill Arjav Jain 500083556");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}