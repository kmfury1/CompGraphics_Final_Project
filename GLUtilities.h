//Filename: GLUtilities.h
//Description: Custom Utilities for OpenGL
//Author: Kaiden Fury
//Date Modified: 10/23/25

#pragma once
#if !defined(_GL_UTILITIES_H_)
#define _GL_UTILITIES_H_

#include <iostream>
using namespace std;

#if defined __APPLE__
    #include <GLUT/glut.h>
#elif defined _WIN32 || defined _WIN64
    #include <GL/glut.h>
#elif __linux__ 
    #include <GL/freeglut.h>
#endif

void drawBitmapText(char *text, void *font, GLfloat x, GLfloat y);
int getBitmapTextWidth(char *text, void *font);
void drawStrokeText(char *text, void *font, GLfloat x, GLfloat y, GLfloat z);
int getStrokeTextWidth(char *text, void *font);
void drawCube(float w, float h, float d);
void drawShip();


#endif //_GL_UTILITIES_H_