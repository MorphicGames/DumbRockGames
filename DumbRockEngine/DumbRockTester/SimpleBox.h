#ifndef _SIMPLEBOX_H
#define _SIMPLEBOX_H

#pragma once

#include "Model.h"

class SimpleBox : public DRE::Model
{
private:
	static GLfloat m_ModelData;
	static GLuint m_ModelIndices;

	GLuint m_ModelIndices[] = 
	{
		0, 1, 2,
		2, 3, 0,
		0, 4, 1,
		1, 5, 4,
		0, 4, 3,
		3, 7, 4,
		4, 5, 6,
		6, 7, 4,
		1, 5, 6,
		6, 2, 1,
		3, 7, 6,
		6, 2, 3
	};

public:
	SimpleBox();

	virtual ~SimpleBox();
};

#endif