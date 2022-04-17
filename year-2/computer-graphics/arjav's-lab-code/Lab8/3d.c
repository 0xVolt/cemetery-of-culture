#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#define pi 3.1415
float A[8][3] = {{0, 0, 0}, {25, 0, 0}, {0, 25, 0}, {0, 0, 25}, {25, 25, 0}, {25, 0, 25}, {0, 25, 25}, {25, 25, 25}};
float B[8][3] = {{0, 0, 0}, {25, 0, 0}, {0, 25, 0}, {0, 0, 25}, {25, 25, 0}, {25, 0, 25}, {0, 25, 25}, {25, 25, 25}};
float x, y, z;
double angle;
int k, c, p;
void init()
{
    glEnable(GL_DEPTH_TEST);
    glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);
}
void translation()
{
    printf("\nEnter Translation Distance along X, Y and Z axes:");
    scanf("%f%f%f", &x, &y, &z);
    for (int i = 0; i < 8; i++)
    {
        B[i][0] = B[i][0] + x;
        B[i][1] = B[i][1] + y;
        B[i][2] = B[i][2] + z;
    }
}
void rotation()
{
    printf("\nEnter The Angle Of Rotation :");
    scanf("%lf", &angle);
    printf("\n1.Anticlockwise\n2.Clockwise");
    printf("\nEnter Your Choice :");
    scanf("%d", &p);
    if (p == 1)
        angle = (angle * pi) / 180;
    if (p == 2)
        angle = (-angle * pi) / 180;
    printf("\nRotation about:\n1.X-axis\n2.Y-axis\n3.Z-axis");
    printf("\nEnter Your Choice :");
    scanf("%d", &c);
    if (c == 1)
    {
        for (int i = 0; i < 8; i++)
        {
            float t;
            t = B[i][1];
            B[i][1] = (B[i][1] * cos(angle)) - (B[i][2] * sin(angle));
            B[i][2] = (t * sin(angle)) + (B[i][2] * cos(angle));
        }
    }
    else if (c == 2)
    {
        for (int i = 0; i < 8; i++)
        {
            float t;
            t = B[i][0];
            B[i][0] = (B[i][0] * cos(angle)) - (B[i][2] * sin(angle));
            B[i][2] = (t * sin(angle)) + (B[i][2] * cos(angle));
        }
    }
    else if (c == 3)
    {
        for (int i = 0; i < 8; i++)
        {
            float t;
            t = B[i][0];
            B[i][0] = (B[i][0] * cos(angle)) - (B[i][1] * sin(angle));
            B[i][1] = (t * sin(angle)) + (B[i][1] * cos(angle));
        }
    }
    else
        printf("Wrong choice");
}
void scaling()
{
    printf("\nEnter Scaling Factor along X, Y and Z:");
    scanf("%f%f%f", &x, &y, &z);
    for (int i = 0; i < 8; i++)
    {

        B[i][0] = B[i][0] * x;
        B[i][1] = B[i][1] * y;
        B[i][2] = B[i][2] * z;
    }
}
void reflection()
{
    printf("Reflection about:\n1. XY plane\n2. YZ plane\n3. ZX plane");
    printf("\nEnter Your Choice :");
    scanf("%d", &c);
    if (c == 1)
        for (int i = 0; i < 8; i++)
            B[i][2] = -B[i][2];
    else if (c == 2)
        for (int i = 0; i < 8; i++)
            B[i][0] = -B[i][0];
    else if (c == 3)
        for (int i = 0; i < 8; i++)
            B[i][1] = -B[i][1];
    else
        printf("Wrong Choice\n");
}
void shearing()
{
    printf("\nEnter X, Y and Z Shearing Factor :");
    scanf("%f%f%f", &x, &y, &z);
    for (int i = 0; i < 8; i++)
    {
        B[i][0] = B[i][0] + y * B[i][1] + z * B[i][2];
        B[i][1] = B[i][1] + x * B[i][0] + z * B[i][2];
        B[i][2] = B[i][2] + x * B[i][0] + y * B[i][1];
    }
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0, 100);
    glVertex2f(0, -100);
    glVertex2f(100, 0);
    glVertex2f(-100, 0);
    glEnd();
    glRotatef(20, 1.0, 0.0, 0.0);
    glRotatef(-20, 0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3fv(A[6]);
    glVertex3fv(A[7]);
    glVertex3fv(A[5]);
    glVertex3fv(A[3]);
    glColor3f(0.7f, 0.0f, 0.0f);
    glVertex3fv(A[2]);
    glVertex3fv(A[4]);
    glVertex3fv(A[1]);
    glVertex3fv(A[0]);
    glColor3f(0.7f, 0.0f, 0.0f);
    glVertex3fv(A[6]);
    glVertex3fv(A[2]);
    glVertex3fv(A[0]);
    glVertex3fv(A[3]);
    glColor3f(0.7f, 0.0f, 0.0f);
    glVertex3fv(A[7]);
    glVertex3fv(A[4]);
    glVertex3fv(A[1]);
    glVertex3fv(A[5]);
    glColor3f(0.7f, 0.0f, 0.0f);
    glVertex3fv(A[6]);
    glVertex3fv(A[2]);
    glVertex3fv(A[4]);
    glVertex3fv(A[7]);
    glColor3f(0.7f, 0.0f, 0.0f);
    glVertex3fv(A[3]);
    glVertex3fv(A[0]);
    glVertex3fv(A[1]);
    glVertex3fv(A[5]);
    glEnd();
    glFlush();
    glutSwapBuffers();
    while (1)
    {
        printf("1.Translate\n2.Rotate\n3.Scale\n4.Reflect\n5.Shear\n0.Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d", &k);
        if (k == 1)
            translation();
        else if (k == 2)
            rotation();
        else if (k == 3)
            scaling();
        else if (k == 4)
            reflection();
        else if (k == 5)
            shearing();
        else if (k == 0)
            break;
        else
            printf("Wrong Choice\n");
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0, 100);
        glVertex2f(0, -100);
        glVertex2f(100, 0);
        glVertex2f(-100, 0);
        glEnd();
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3fv(B[6]);
        glVertex3fv(B[7]);
        glVertex3fv(B[5]);
        glVertex3fv(B[3]);
        glColor3f(0.0f, 0.0f, 0.7f);
        glVertex3fv(B[2]);
        glVertex3fv(B[4]);
        glVertex3fv(B[1]);
        glVertex3fv(B[0]);
        glColor3f(0.0f, 0.0f, 0.7f);
        glVertex3fv(B[6]);
        glVertex3fv(B[2]);
        glVertex3fv(B[0]);
        glVertex3fv(B[3]);
        glColor3f(0.0f, 0.0f, 0.7f);
        glVertex3fv(B[7]);
        glVertex3fv(B[4]);
        glVertex3fv(B[1]);
        glVertex3fv(B[5]);
        glColor3f(0.0f, 0.0f, 0.7f);
        glVertex3fv(B[6]);
        glVertex3fv(B[2]);
        glVertex3fv(B[4]);
        glVertex3fv(B[7]);
        glColor3f(0.0f, 0.0f, 0.7f);
        glVertex3fv(B[3]);
        glVertex3fv(B[0]);
        glVertex3fv(B[1]);
        glVertex3fv(B[5]);
        glEnd();
        glFlush();
        glutSwapBuffers();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("3D Tranformations Arjav Jain 500083556");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}