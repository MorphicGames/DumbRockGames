#ifndef _MESH_H
#define _MESH_H

#pragma once

#include <vector>

#include "Texture.h"
#include "ShaderProgram.h"
#include "OpenGL\glm\glm\glm.hpp"
#include "OpenGL\glew-1.13.0\include\GL\glew.h"

namespace DRE
{
	struct Vertex {
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec2 textureCoords;
	};

	class Mesh
	{
	private:
		GLuint VAO, VBO, EBO;

		void SetupMesh()
		{
			glGenVertexArrays(1, &this->VAO);
			glGenBuffers(1, &this->VBO);
			glGenBuffers(1, &this->EBO);

			glBindVertexArray(this->VAO);
			glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

			glBufferData(GL_ARRAY_BUFFER, this->vertices.size() & sizeof(Vertex), &this->vertices[0], GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);

			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),(GLvoid*)0);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),(GLvoid*)offsetof(Vertex, normal));
			glEnableVertexAttribArray(2);
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),(GLvoid*)offsetof(Vertex, textureCoords));

			glBindVertexArray(0);
		}

	public:
		std::vector<Vertex> vertices;
		std::vector<GLuint> indices;
		std::vector<Texture> textures;

		Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures)
		{
			this->vertices	= vertices;
			this->indices	= indices;
			this->textures	= textures;

			this->SetupMesh();
		}

		void Render(ShaderProgram program)
		{
			GLuint diffuseNr = 1;
			GLuint specularNr = 1;
			for (GLuint i = 0; i < this->textures.size(); i++)
			{
				glActiveTexture(GL_TEXTURE0 + i);

				std::stringstream ss;
				std::string number;
				std::string name = this->textures[i].type;
				if (name == "texture_diffuse") {
					ss << diffuseNr++;
				}
				else if (name == "texture_specular") {
					ss << specularNr++;
				}
				number = ss.str();

				glUniform1f(glGetUniformLocation(program.GetProgram(), ("material." + name + number).c_str()), i);
				glBindTexture(GL_TEXTURE_2D, this->textures[i].id);
			}
			glActiveTexture(GL_TEXTURE0);

			glBindVertexArray(this->VAO);
			glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}
	};
}

#endif