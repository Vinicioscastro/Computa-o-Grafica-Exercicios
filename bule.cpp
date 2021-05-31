// opengl.cpp : Defines the entry point for the console application.
//



#include <windows.h>
#include "GL/glut.h"



void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.314, 0.5, 0.000);
	/**
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);*/
	glColor3f(1.0, 0.3, 0.000);
	glutSolidTeapot(0.5);
	glEnd();
	glFlush();
}

void init()
{
	glClearColor(1.000, 1.00, 1.00, 0.0); // brackground color

	glColor3f(0.314, 0.5, 0.000); // JMU Purple

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("prueva de opengl");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}