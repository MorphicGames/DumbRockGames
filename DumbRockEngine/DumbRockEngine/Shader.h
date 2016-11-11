#ifndef _SHADER_H
#define _SHADER_H

#pragma once

#include <string>
#include <fstream>
#include <sstream>

#include <glew.h>

namespace DRE
{
	enum ShaderType
	{
		VERTEX,
		FRAGMENT,
		TESSELLATION,
		GEOMETRY
	};

	class Shader
	{
	private:
		GLuint program;

	public:
		Shader(const GLchar* filename, const ShaderType& shaderType);

		void UseShader();
	};
}

#endif