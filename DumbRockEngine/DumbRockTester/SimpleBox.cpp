#include "SimpleBox.h"

GLfloat SimpleBox::m_ModelData[] = 
{
	//Position		    //Colour	    //Texture
	0.0f, 0.0f, 0.0f,	1.0f, 0.0f, 0.0f,	0.0f, 0.0f,
	0.5f, 0.0f, 0.0f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
	0.5f, 0.5f, 0.0f,	0.0f, 0.0f, 1.0f,	0.0f, 0.0f,
	0.0f, 0.5f, 0.0f,	1.0f, 0.0f, 0.0f,	0.0f, 0.0f,
	0.0f, 0.0f, 0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
	0.5f, 0.0f, 0.5f,	0.0f, 0.0f, 1.0f,	0.0f, 0.0f,
	0.5f, 0.5f, 0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 0.0f,
	0.0f, 0.5f, 0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f
};

SimpleBox::SimpleBox()
{

}

SimpleBox::~SimpleBox()
{

}