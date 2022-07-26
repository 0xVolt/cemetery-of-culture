#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdio.h>

void init(void)
{
	glClearColor(0, 0.5, 1, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-600, 600, -500, 550);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	// Triangle
	glColor3f(0, 1, 0);
	glBegin(GL_TRIANGLES);
        glVertex2f(-450, 450);
        glVertex2f(-400, 300);
        glVertex2f(-500, 300);
	glEnd();

	glColor3f(1, 1, 1);
	glRasterPos2f(-500, 270);
	const unsigned char *a = reinterpret_cast<const unsigned char *>("Bharat\'s Triangle");
	glutBitmapString(GLUT_BITMAP_HELVETICA_12, a);

	// LINE
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
        glVertex2f(-350, 300);
        glVertex2f(-300, 450);
	glEnd();

	glColor3f(1, 1, 1);
	glRasterPos2f(-350, 270);
	const unsigned char *b = reinterpret_cast<const unsigned char *>("Bharat\'s Line");
	glutBitmapString(GLUT_BITMAP_HELVETICA_12, b);

    // Hexagon
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
        glVertex2f(-0.3,0.8);
        glVertex2f(-0.4,0.6);
        glVertex2f(-0.3,0.4);
        glVertex2f(0.2,0.8);
        glVertex2f(0.3,0.6);
        glVertex2f(0.2,0.4);
        glVertex2f(-0.2,0.4);
        glVertex2f(-0.3,0.4);
	glEnd();

	// Hexagon
	glColor3f(1,1,1);
	glRasterPos2f(-0.2,0.0);
	glRasterPos2f(-350, 270);
	const unsigned char *c = reinterpret_cast<const unsigned char *>("Bharat\'s Hexagon");
	glutBitmapString(GLUT_BITMAP_HELVETICA_12, c);

	/*

	glColor3f(0,1,0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(0.9,0.9);
	glVertex2f(0.9,0.7);
	glVertex2f(0.5,0.6);
	glEnd();

	glColor3f(0,1,0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-0.2,-0.60);
	glVertex2f(0.0, -0.50);
	glVertex2f(-0.1, -0.20);
	glVertex2f(0.2,-0.60);
	glVertex2f(0.1,-0.30);
	glVertex2f(0.35,-0.20);
	glEnd();

	//glColor3f(1,1,1);
	//glRasterPos2f(0.70,0.50);
	//glutBitmapString(GLUT_BITMAP_HELVETICA_18,"BHARAT");



	//glBegin(GL_QUADS);
	//glColor3f(0,1,0);
	//glVertex2f(-0.8,0.8);
	//glVertex2f(-0.5,0.10);
	//glVertex2f(-0.3,0.20);
	//glVertex2f(0.2,0.40);
	//glVertex2f(0.3,0.30);
	//glVertex2f(0.3,0.15);
	//glVertex2f(0.2,0.05);
	//glVertex2f(0.05,0.17);
	//glEnd();

	   glBegin(GL_QUAD_STRIP);
	glColor3f(0,1,0);
	glVertex2f(0.5,0.15);
	glVertex2f(0.5,0.45);

	glVertex2f(0.65,0.2);
	glVertex2f(0.6,0.4);

	glVertex2f(0.7,0.15);
	glVertex2f(0.7,0.45);

	glVertex2f(0.8,0.13);
	glVertex2f(0.9,0.4);
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,1,0);
	glVertex2f(0.5,-0.60);
	glVertex2f(0.55,-0.30);
	glVertex2f(0.7,-0.40);
	glColor3f(1,0,0);
	glColor3f(0,1,0);
	glColor3f(1,1,0);
	glEnd();

	 glBegin(GL_LINE_LOOP);
	glColor3f(0,270,0);
	glVertex2f(0.95, 0.81);
	glVertex2f(0.1, 0.79);
	glVertex2f(0.3, 0.88);
	glVertex2f(0.2, 0.61);
	glVertex2f(0.4, 0.70);
	glVertex2f(0.2, 0.65);
	glEnd();
	*/
	glFlush();
}
void onclick(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		glClearColor(1, 0, 0, 0);
		glutPostRedisplay();
	}
}
void onclick1(char key, int x, int y)
{
	if (key == 'a')
	{
		exit(1);
	}
}

int main(int argc, char **argv)

{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("Primitives Task");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(onclick);
	// glutKeyboardFunc(onclick1);
	glutMainLoop();
	return 0;
}
