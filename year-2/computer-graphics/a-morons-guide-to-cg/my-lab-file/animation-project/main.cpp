#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

// Initially which dir
float change_X = 0, change_Y = 1;

// Offsets
float x = 3, y = 4;

// Rotation angle
float theta = 0;

// Round-off function for easier calcs
float approx(float x)
{
    if (x > 0.75)
        return 1;
    else if (x < -0.75)
        return -1;
    else
        return 0;
}

// Circular movement which is statically controlled
void Circular_Direction_Control()
{
    // Starts in bottom-left
    srand(time(0));

    // If y coord hits top-left, change dirn 
    if (y > 48 && x < 142)
    {
        change_X = 1;
        change_Y = 0;
        theta = -90;
    }
    // If y coord hits top-right, change dirn 
    if (y > 48 && x > 142)
    {
        change_X = 0;
        change_Y = -1;
        theta = 180;
    }
    // If y coord hits bottom-right, change dirn 
    if (y < 2 && x > 8)
    {
        change_X = -1;
        change_Y = 0;
        theta = 90;
    }
    // If y coord hits bottom-left, change dirn 
    if (y < 2 && x < 8)
    {
        change_X = 0;
        change_Y = 1;
        theta = 0;
    }

    // Rate of change of position, i.e., speed. duh.
    x += change_X * 0.08;
    y += change_Y * 0.08;
}

// For randomizing the dirn in which the object travels after it encounters the boundary conditions
void Random_Direction_Control()
{
    srand(time(0));
    if (y > 48 && x < 8)
    {
        // Goes right
        if (rand() % 2 == 0)
        {
            change_X = 1;
            change_Y = 0;
            theta = -90;
        }
        // Goes back down
        else
        {
            change_X = 0;
            change_Y = -1;
            theta = 180;
        }
    }
    if (y > 48 && x > 142)
    {
        if (rand() % 2 == 0)
        {
            change_X = 0;
            change_Y = -1;
            theta = 180;
        }
        else
        {
            change_X = -1;
            change_Y = 0;
            theta = 90;
        }
    }
    if (y < 2 && x > 142)
    {
        if (rand() % 2 == 0)
        {
            change_X = -1;
            change_Y = 0;
            theta = 90;
        }
        else
        {
            change_X = 0;
            change_Y = 1;
            theta = 0;
        }
    }
    if (y < 2 && x < 8)
    {
        if (rand() % 2 == 0)
        {
            change_X = 0;
            change_Y = 1;
            theta = 0;
        }
        else
        {
            change_X = 1;
            change_Y = 0;
            theta = -90;
        }
    }

    x += change_X * 0.08;
    y += change_Y * 0.08;
}

// Formulae for calculating the rotation transformation
// Xnew = [Xold * cos(theta)] - [Yold * sin(theta)]
// Ynew = [Xold * sin(theta)] + [Yold * cos(theta)]
// For every vertex in the figure
void Animation()
{
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);

    glVertex2f((0) * approx(cos(theta * 11 / 630)) - (17) * approx(sin(theta * 11 / 630)) + x, (0) * approx(sin(theta * 11 / 630)) + (17) * approx(cos(theta * 11 / 630)) + y);

    glVertex2f((-2) * approx(cos(theta * 11 / 630)) - (13) * approx(sin(theta * 11 / 630)) + x, (-2) * approx(sin(theta * 11 / 630)) + (13) * approx(cos(theta * 11 / 630)) + y);

    glVertex2f((2) * approx(cos(theta * 11 / 630)) - (13) * approx(sin(theta * 11 / 630)) + x, (2) * approx(sin(theta * 11 / 630)) + (13) * approx(cos(theta * 11 / 630)) + y);

    glEnd();
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);

    glVertex2f((-2) * approx(cos(theta * 11 / 630)) - (13) * approx(sin(theta * 11 / 630)) + x, (-2) * approx(sin(theta * 11 / 630)) + (13) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((2) * approx(cos(theta * 11 / 630)) - (13) * approx(sin(theta * 11 / 630)) + x, (2) * approx(sin(theta * 11 / 630)) + (13) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((0) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (0) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    
    glVertex2f((0) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (0) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((-2) * approx(cos(theta * 11 / 630)) - (13) * approx(sin(theta * 11 / 630)) + x, (-2) * approx(sin(theta * 11 / 630)) + (13) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((-4) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (-4) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    
    glVertex2f((0) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (0) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((2) * approx(cos(theta * 11 / 630)) - (13) * approx(sin(theta * 11 / 630)) + x, (2) * approx(sin(theta * 11 / 630)) + (13) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((4) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (4) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    
    glEnd();
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    
    glVertex2f((0) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (0) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((-2) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (-2) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((-4) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (-4) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    
    glEnd();
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    
    glVertex2f((0) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (0) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((2) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (2) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((4) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (4) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    
    glVertex2f((-6) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (-6) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((-2) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (-2) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((-4) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (-4) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    
    glVertex2f((6) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (6) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((2) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (2) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((4) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (4) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    
    glEnd();
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    
    glVertex2f((-6) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (-6) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((-2) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (-2) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((-4) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (-4) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    
    glEnd();
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    
    glVertex2f((6) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (6) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((2) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (2) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((4) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (4) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    
    glVertex2f((-6) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (-6) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((-8) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (-8) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((-4) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (-4) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    
    glVertex2f((6) * approx(cos(theta * 11 / 630)) - (5) * approx(sin(theta * 11 / 630)) + x, (6) * approx(sin(theta * 11 / 630)) + (5) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((8) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (8) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((4) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (4) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    
    glEnd();
    glColor3f(1, 0.5, 0.7);
    glBegin(GL_POLYGON);
    
    glVertex2f((0) * approx(cos(theta * 11 / 630)) - (9) * approx(sin(theta * 11 / 630)) + x, (0) * approx(sin(theta * 11 / 630)) + (9) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((-4) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (-4) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((4) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (4) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    
    glEnd();
    glColor3f(0.3, 0.5, 1);
    glBegin(GL_POLYGON);
    
    glVertex2f((-2) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (-2) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((-8) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (-8) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((-12) * approx(cos(theta * 11 / 630)) - (-7) * approx(sin(theta * 11 / 630)) + x, (-12) * approx(sin(theta * 11 / 630)) + (-7) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((-2) * approx(cos(theta * 11 / 630)) - (-7) * approx(sin(theta * 11 / 630)) + x, (-2) * approx(sin(theta * 11 / 630)) + (-7) * approx(cos(theta * 11 / 630)) + y);
    
    glEnd();
    glColor3f(0.3, 0.5, 1);
    glBegin(GL_POLYGON);
    
    glVertex2f((2) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (2) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((8) * approx(cos(theta * 11 / 630)) - (1) * approx(sin(theta * 11 / 630)) + x, (8) * approx(sin(theta * 11 / 630)) + (1) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((12) * approx(cos(theta * 11 / 630)) - (-7) * approx(sin(theta * 11 / 630)) + x, (12) * approx(sin(theta * 11 / 630)) + (-7) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((2) * approx(cos(theta * 11 / 630)) - (-7) * approx(sin(theta * 11 / 630)) + x, (2) * approx(sin(theta * 11 / 630)) + (-7) * approx(cos(theta * 11 / 630)) + y);
    
    glEnd();
    glColor3f(1, 0.5, 0.7);
    glBegin(GL_POLYGON);
    
    glVertex2f((-2) * approx(cos(theta * 11 / 630)) - (-7) * approx(sin(theta * 11 / 630)) + x, (-2) * approx(sin(theta * 11 / 630)) + (-7) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((-12) * approx(cos(theta * 11 / 630)) - (-7) * approx(sin(theta * 11 / 630)) + x, (-12) * approx(sin(theta * 11 / 630)) + (-7) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((-2) * approx(cos(theta * 11 / 630)) - (-17) * approx(sin(theta * 11 / 630)) + x, (-2) * approx(sin(theta * 11 / 630)) + (-17) * approx(cos(theta * 11 / 630)) + y);
    
    glEnd();
    glColor3f(1, 0.5, 0.7);
    glBegin(GL_POLYGON);
    
    glVertex2f((2) * approx(cos(theta * 11 / 630)) - (-7) * approx(sin(theta * 11 / 630)) + x, (2) * approx(sin(theta * 11 / 630)) + (-7) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((12) * approx(cos(theta * 11 / 630)) - (-7) * approx(sin(theta * 11 / 630)) + x, (12) * approx(sin(theta * 11 / 630)) + (-7) * approx(cos(theta * 11 / 630)) + y);
    
    glVertex2f((2) * approx(cos(theta * 11 / 630)) - (-17) * approx(sin(theta * 11 / 630)) + x, (2) * approx(sin(theta * 11 / 630)) + (-17) * approx(cos(theta * 11 / 630)) + y);
    
    glEnd();
    glFlush();
    glClear(GL_COLOR_BUFFER_BIT);

    // Random_Direction_Control();
    Circular_Direction_Control();

    glutPostRedisplay();
}

void background_design()
{
    glColor3f(0, 0.67, 1);
    glBegin(GL_TRIANGLES);
    glVertex2f(-25, -25);
    glVertex2f(-17.5, -25);
    glVertex2f(-25, 75);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(175, 75);
    glVertex2f(-25, 67.5);
    glVertex2f(-25, 75);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(175, 75);
    glVertex2f(167.5, 75);
    glVertex2f(175, -25);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(-25, -25);
    glVertex2f(175, -17.5);
    glVertex2f(175, -25);
    glEnd();
}

void markers()
{
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-13, -10);
    glVertex2f(-9, -10);
    glVertex2f(-9, 6);
    glVertex2f(-13, 6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0, 69);
    glVertex2f(16, 69);
    glVertex2f(16, 65);
    glVertex2f(0, 65);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(163, 60);
    glVertex2f(159, 60);
    glVertex2f(159, 44);
    glVertex2f(163, 44);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(150, -19);
    glVertex2f(134, -19);
    glVertex2f(134, -15);
    glVertex2f(150, -15);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(163, -10);
    glVertex2f(159, -10);
    glVertex2f(159, 6);
    glVertex2f(163, 6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0, -19);
    glVertex2f(16, -19);
    glVertex2f(16, -15);
    glVertex2f(0, -15);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-13, 60);
    glVertex2f(-9, 60);
    glVertex2f(-9, 44);
    glVertex2f(-13, 44);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(150, 69);
    glVertex2f(134, 69);
    glVertex2f(134, 65);
    glVertex2f(150, 65);
    glEnd();
}

void Setup()
{
    background_design();
    markers();
    Animation();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Desh Iyer | Computer Graphics Lab | Project");

    // BG Color
    glClearColor(.13, .48, .67, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-25, 175, -25, 75);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(Setup);
    glutMainLoop();

    return 0;
}
