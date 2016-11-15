#ifndef _MODEL_H
#define _MODEL_H

#pragma once

#include "DRE_typedef.h"

#include "OpenGL\glew-1.13.0\include\GL\glew.h"

namespace DRE
{
	class Model
	{
	private:
		GLuint m_VAO;
		U32 m_FaceCount;

	public:
		Model(GLfloat meshData[], U32 faceCount, GLuint indices[]) 
			: m_FaceCount(faceCount)
		{
			GLuint VBO;
			glGenBuffers(1, &VBO);

			glGenVertexArrays(1, &m_VAO);

			GLuint EBO;
			glGenBuffers(1, &EBO);

			glBindVertexArray(m_VAO);
				glBindBuffer(GL_ARRAY_BUFFER, VBO);
				glBufferData(GL_ARRAY_BUFFER, sizeof(meshData), meshData, GL_STATIC_DRAW);

				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
				glEnableVertexAttribArray(0);

				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
				glEnableVertexAttribArray(1);

				glVertexAttribPointer(2, 2, GL_UNSIGNED_INT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
				glEnableVertexAttribArray(2);
			glBindVertexArray(0);
		}

		GLuint GetVAO() const
		{
			return m_VAO;
		}

		U32 GetFaceCount() const
		{
			return m_FaceCount;
		}
	};
}

#endif
