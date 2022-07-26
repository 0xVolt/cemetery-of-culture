## Cheat Sheet for GLUT commands - Computer Graphics

### Boilerplate main() function
    // Its best practice to take user inputs and perform calculations before inserting this block to init glut and its functions
    int main(int argc, char** argv) {
        // Inits glut
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        
        // Window dimensions and position
        glutInitWindowSize(500, 500);
        glutInitWindowPosition(80, 54);

        // Create the window to display graphics
        glutCreateWindow("Window Name");

        // Set background 
        glClearColor(0,0,0,0);
        glMatrixMode(GL_PROJECTION);
        
        // Point size
        glPointSize(4);
        glLoadIdentity();

        // Make a set of points for 2D
        gluOrtho2D(0,200,0,200);

        // Configure how the model is viewed
        glMatrixMode(GL_MODELVIEW);

        glutDisplayFunc(function_to_call());
        glutMainLoop();
    }

### Set Window Background Colour
    glClearColor(R, G, B, alpha);

### Clear Buffer 
    glClear(GL_COLOR_BUFFER_BIT);

### Graphic "Braces"
Put the code in between the start and the end (like generating shapes using verteces in Processing)
        
    // For lines
    glBegin(GL_LINES)

*Note: For different shapes, the argument to begin the shape would be different*

    // To end the block where graphics are generated, use
    glEnd();
    glFlush();

### Color whatever the graphic is
    glColor3f(R, G, B, alpha)

## Function to display a line in 2D
    // For a white BG
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);

*Note: To display a line in 3D, just change the `glVertex2f(x, y)` to `glVertex3f(x, y, z)`.*