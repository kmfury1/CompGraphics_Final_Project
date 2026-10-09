// Filename: Fury_FinalProject.cpp
// Description: Solar System
// Author: Kaiden Fury
// Date Modified: 12/06/25

#include "GLUtilities.h"



// Function Prototypes...
void display(void);
void reshape(GLsizei width, GLsizei height);

GLsizei windowWidth = 640;
GLsizei windowHeight = 480;

int main(int argc, char **argv)
{
    // Initialization functions...
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); // Use double buffer mode and depth buffer
    glutInitWindowSize(windowWidth, windowHeight); // set the window's initial width and height
    glutCreateWindow("Cruise Ship!!");
    glEnable(GL_DEPTH_TEST);

    // Callback Functions...
    glutDisplayFunc(&display);
    glutReshapeFunc(&reshape);
    glutMainLoop();
   
    
    return 0;
}

void display(void) 
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // use the depth buffer
    glLoadIdentity();                                   // reset stuff in current mode

    drawShip();
    glutSwapBuffers();

}
void reshape(GLsizei width, GLsizei height)
{
    // cout << "Resizing" << endl;

    if (height <= 0)
        height = 1; // Sanity!
    if (width <= 0)
        width = 1; // Sanity!

    windowWidth = width;
    windowHeight = height;


    // Set the viewpoint to cover the entire window
    glViewport(0, 0, width, height);

    glutPostRedisplay();
}