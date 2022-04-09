#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#define pi 3.1415
float x[100], y[100];
float p[100], m[100];
int n, k, c;
double angle;
float a, b;
void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200, 200, -200, 200);
}
void translation()
{
    printf("\nEnter Translation Distance along X and Y axis:");
    scanf("%f%f", &a, &b);
    for (int i = 0; i < n; i++)
    {
        p[i] += a;
        m[i] += b;
    }
}
void rotation()
{
    printf("\nEnter The Angle Of Rotation :");
    scanf("%lf", &angle);
    printf("\n1.Anticlockwise\n2.Clockwise");
    printf("\nEnter Your Choice :");
    scanf("%d", &c);
    printf("\nEnter the point about which Rotation is to be done:");
    scanf("%f%f", &a, &b);
    if (c == 1)
        angle = (angle * pi) / 180;
    if (c == 2)
        angle = (-angle * pi) / 180;
    for (int i = 0; i < n; i++)
    {
        p[i] -= a;
        m[i] -= b;
    }
    for (int i = 0; i < n; i++)
    {
        float t1, t2;
        t1 = p[i];
        t2 = m[i];
        p[i] = (t1 * cos(angle)) - (t2 * sin(angle));
        m[i] = (t1 * sin(angle)) + (t2 * cos(angle));
    }
    for (int i = 0; i < n; i++)
    {
        p[i] += a;
        m[i] += b;
    }
}
void scaling()
{
    printf("\nEnter Scaling Factor along X and Y:");
    scanf("%f%f", &a, &b);
    for (int i = 0; i < n; i++)
    {
        p[i] *= a;
        m[i] *= b;
    }
}
void reflection()
{
    printf("Reflection about:\n1. X-axis\n2. Y-axis\n3. X=Y\n4. X=-Y\n5. Origin\n6. An arbitrary line");
    printf("\nEnter Your Choice :");
    scanf("%d", &c);
    if (c == 1)
    {
        for (int i = 0; i < n; i++)
        {
            m[i] = -m[i];
        }
    }
    else if (c == 2)
    {
        for (int i = 0; i < n; i++)
        {
            p[i] = -p[i];
        }
    }
    else if (c == 3)
    {
        for (int i = 0; i < n; i++)
        {
            float temp;
            temp = p[i];
            p[i] = m[i];
            m[i] = temp;
        }
    }
    else if (c == 4)
    {
        for (int i = 0; i < n; i++)
        {
            float temp;
            temp = -p[i];
            p[i] = -m[i];
            m[i] = temp;
        }
    }
    else if (c == 5)
    {
        for (int i = 0; i < n; i++)
        {
            p[i] = -p[i];
            m[i] = -m[i];
        }
    }
    else if (c == 6)
    {
        float m1;
        printf("\nEnter Slope And Intercept Of The Line : ");
        scanf("%f%d", &m1, &c);
        for (int i = 0; i < n; i++)
        {
            m[i] -= c;
        }
        angle = -atan(m1);
        for (int i = 0; i < n; i++)
        {
            float t1, t2;
            t1 = p[i];
            t2 = m[i];
            p[i] = (t1 * cos(angle)) - (t2 * sin(angle));
            m[i] = (t1 * sin(angle)) + (t2 * cos(angle));
        }
        for (int i = 0; i < n; i++)
        {
            m[i] = -m[i];
        }
        angle = -angle;
        for (int i = 0; i < n; i++)
        {
            float t1, t2;
            t1 = p[i];
            t2 = m[i];
            p[i] = (t1 * cos(angle)) - (t2 * sin(angle));
            m[i] = (t1 * sin(angle)) + (t2 * cos(angle));
        }
        for (int i = 0; i < n; i++)
        {
            m[i] += c;
        }
    }
    else
        printf("Wrong Choice\n");
}
void shearing()
{
    printf("\nEnter X and Y Shearing Factor :");
    scanf("%f%f", &a, &b);
    for (int i = 0; i < n; i++)
    {
        p[i] += a * m[i];
        m[i] += b * p[i];
    }
}
void display(void)
{
    printf("Enter the Number of Vertices :");
    scanf("%d", &n);
    printf("\nEnter the Vertices : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f%f", &x[i], &y[i]);
        p[i] = x[i];
        m[i] = y[i];
    }
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.1f, 0.1f);
    for (int i = 0; i < n; i++)
    {
        glVertex2f(x[i], y[i]);
    }
    glEnd();
    glFlush();
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
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        glColor3f(0.8f, 0.1f, 0.1f);
        for (int i = 0; i < n; i++)
        {
            glVertex2f(p[i], m[i]);
        }
        glEnd();
        glFlush();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("2D Tranformations");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}