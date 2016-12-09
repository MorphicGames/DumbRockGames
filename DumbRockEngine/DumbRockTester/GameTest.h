#ifndef _GAMETEST_H
#define _GAMETEST_H

#pragma once

#include "OpenGL\glew-1.13.0\include\GL\glew.h"
#include "OpenGL\glut-3.7.6\include\GL\glut.h"

class GameTest
{
public:
	int width = 1600;
	int height = 900;

	void Initialize(int argc, char** argv)
	{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
		glutInitWindowSize(width, height);
		glutInitWindowPosition(50, 50);

		glutCreateWindow("Totally the DumbRockEngine");

		//glewInit();

		glEnable(GL_DEPTH_TEST);

		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1, 100000.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glClearColor(1.0, 1.0, 1.0, 1.0);
	}

	void Run()
	{

	}

	void Idle()
	{
		glutPostRedisplay();
	}

	void Reshape(int w, int h)
	{
		glViewport(0, 0, (GLsizei)width, (GLsizei)height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1, 100000.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	void Display() 
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Keyboard(unsigned char key, int x, int y)
	{

	}

	void Mouse(int button, int state, int x, int y)
	{

	}
};

#endif