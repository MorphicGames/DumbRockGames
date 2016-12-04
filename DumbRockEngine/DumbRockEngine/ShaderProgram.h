#ifndef _SHADERPROGRAM_H
#define _SHADERPROGRAM_H

#pragma once

#include "ShaderManager.h"

#include "OpenGL\glew-1.13.0\include\GL\glew.h"

class Shader;

namespace DRE
{
	class ShaderProgram
	{
	private:
		GLuint m_Program;

	public:
		ShaderProgram();
		~ShaderProgram();

		GLuint GetProgram() const;

		void AttachShader(const Shader& shader);
		void AttachShader(const std::string& shaderName);
		void DetachShader(const Shader& shader);
		void DetachShader(const std::string& shaderName);

		void LinkProgram();

		void UseProgram();
	};
}

#endif 