#ifndef _MODEL_H
#define _MODEL_H

#pragma once

#include <glew.h>

namespace DRE
{
	class Model
	{
	private:
		GLuint* m_VAO;

	public:
		Model(GLfloat* vertices, GLfloat* colour, GLfloat* UV, GLfloat* indices) {
			GLuint VBO;
			glGenBuffers(1, &VBO);

			glGenVertexArrays(1, m_VAO);

			GLuint EBO;
			glGenBuffers(1, &EBO);

			glBindVertexArray(*m_VAO);
				glBindBuffer(GL_ARRAY_BUFFER, VBO);
				glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
				glEnableVertexAttribArray(0);
			glBindVertexArray(0);

		}

		~Model() {
			delete[] m_VAO;
			m_VAO = nullptr;
		}
	};
}

#endif
