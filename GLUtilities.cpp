//Filename: GLUtilities.cpp
//Description: See header file for more information
//Author: Kaiden Fury
//Date Modified: 10/23/25

#include "GLUtilities.h"

void drawBitmapText(char *text, void *font, GLfloat x, GLfloat y)
{
    char *c;
    glPushMatrix();
    glRasterPos2f(x, y);
    for (c=text; *c; c++)
    {
        glutBitmapCharacter(font, *c);
    }
    glPopMatrix();
}
int getBitmapTextWidth(char *text, void *font)
{
    char *c;
    int w = 0;
    for (c=text; *c; c++)
    {
       w += glutBitmapWidth(font, *c);
    }
    return w;
}
void drawStrokeText(char *text, void *font, GLfloat x, GLfloat y, GLfloat z)
{
    char *c;
    glPushMatrix();
    glTranslatef(x, y, z);
    for (c=text; *c; c++)
    {
        glColor3f(rand()/(GLfloat)RAND_MAX, rand()/(GLfloat)RAND_MAX, rand()/(GLfloat)RAND_MAX);
        glutStrokeCharacter(font, *c);
    }
    glPopMatrix();
}
int getStrokeTextWidth(char *text, void *font)
{
    char *c;
    int w = 0;
    for (c=text; *c; c++)
    {
       w += glutStrokeWidth(font, *c);
    }
    return w;
}
void drawCube(float w, float h, float d)
{
    glBegin(GL_QUADS);

    // FRONT
    glNormal3f(0,0,1);
    glVertex3f(-w/2, -h/2,  d/2);
    glVertex3f( w/2, -h/2,  d/2);
    glVertex3f( w/2,  h/2,  d/2);
    glVertex3f(-w/2,  h/2,  d/2);

    // BACK
    glNormal3f(0,0,-1);
    glVertex3f(-w/2, -h/2, -d/2);
    glVertex3f( w/2, -h/2, -d/2);
    glVertex3f( w/2,  h/2, -d/2);
    glVertex3f(-w/2,  h/2, -d/2);

    // LEFT
    glNormal3f(-1,0,0);
    glVertex3f(-w/2, -h/2, -d/2);
    glVertex3f(-w/2, -h/2,  d/2);
    glVertex3f(-w/2,  h/2,  d/2);
    glVertex3f(-w/2,  h/2, -d/2);

    // RIGHT
    glNormal3f(1,0,0);
    glVertex3f(w/2, -h/2, -d/2);
    glVertex3f(w/2, -h/2,  d/2);
    glVertex3f(w/2,  h/2,  d/2);
    glVertex3f(w/2,  h/2, -d/2);

    // TOP
    glNormal3f(0,1,0);
    glVertex3f(-w/2, h/2, -d/2);
    glVertex3f( w/2, h/2, -d/2);
    glVertex3f( w/2, h/2,  d/2);
    glVertex3f(-w/2, h/2,  d/2);

    // BOTTOM
    glNormal3f(0,-1,0);
    glVertex3f(-w/2, -h/2, -d/2);
    glVertex3f( w/2, -h/2, -d/2);
    glVertex3f( w/2, -h/2,  d/2);
    glVertex3f(-w/2, -h/2,  d/2);

    glEnd();
}
void drawShip()
{
    glPushMatrix();

    // 🚢 HULL (Bottom)
    glColor3f(0.2f, 0.2f, 0.8f);
    glTranslatef(0, -1.0f, 0);
    drawCube(4.0f, 1.0f, 12.0f);
    glPopMatrix();

    glPushMatrix();
    // DECK
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(0, 0.0f, 0);
    drawCube(3.8f, 0.4f, 10.0f);
    glPopMatrix();

    glPushMatrix();
    // BRIDGE
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0, 1.0f, 3.0f);
    drawCube(1.6f, 1.0f, 2.0f);
    glPopMatrix();

    // SMOKESTACKS
    glPushMatrix();
    glColor3f(0.1f, 0.1f, 0.1f);
    glTranslatef(-1.0f, 1.8f, -2.0f);
    drawCube(0.4f, 1.2f, 0.4f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0f, 1.8f, -2.0f);
    drawCube(0.4f, 1.2f, 0.4f);
    glPopMatrix();

}