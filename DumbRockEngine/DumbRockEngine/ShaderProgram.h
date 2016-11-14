#ifndef _SHADERPROGRAM_H
#define _SHADERPROGRAM_H

#pragma once

#include "ShaderManager.h"

#include "OpenGL\glew-1.13.0\include\GL\glew.h"

namespace DRE
{
	class ShaderProgram
	{
	private:
		GLuint m_Program;

		ShaderManager* m_pShaderManager;
	public:
		ShaderProgram(ShaderManager* shaderManager);
		~ShaderProgram();

		void AttachShader(const Shader& shader);
		void AttachShader(const std::string& shaderName);
		void DetachShader(const Shader& shader);
		void DetachShader(const std::string& shaderName);

		void LinkProgram();

		void UseProgram();
	};
}

#endif 