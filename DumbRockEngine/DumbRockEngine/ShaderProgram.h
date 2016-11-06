#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#pragma once

#include "OpenGLShaderHandler.h"

#include <vector>

namespace DRE
{
	class ShaderProgram
	{
	private:
		std::string programName;
		bool runnable = false;
		OpenGLShaderHandler* programHandler;

		std::string getCompileMessage() const;

	public:
		ShaderProgram(const std::string& name)
			: programName(name)
			, programHandler(new OpenGLShaderHandler())
		{

		}

		ShaderProgram(const ShaderProgram& other);

		~ShaderProgram();

		void DetachVertexShader();

		void DetechFragmentShader();

		std::string GetVertexShaderName() const;

		std::string GetFragmentShaderName() const;

		void Compile();

		bool IsRunnable();

		std::string GetResourceName() const;

		std::string ToString() const;

		OpenGLShaderHandler* GetShaderHandle() const;

		void RemoveProgramFromGPU();

		int GetNumberVertexVariables() const;
	};
}

#endif