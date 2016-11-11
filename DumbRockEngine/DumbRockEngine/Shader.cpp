#include "Shader.h"

#include "LogManager.h"

namespace DRE
{
	Shader::Shader(const GLchar* filename, const ShaderType& shaderType)
	{
		std::string fileCode;
		std::ifstream shaderFile;

		shaderFile.exceptions(std::ifstream::badbit);

		try
		{
			shaderFile.open(filename);
			std::stringstream shaderStream;

			shaderStream << shaderFile.rdbuf();

			shaderFile.close();

			fileCode = shaderStream.str();
		}
		catch (std::ifstream::failure e)
		{
			LogManager::LogMessage(LogMessageType::ERROR, "File not successfully read", __FILE__, __LINE__);
		}

		const GLchar* shaderCode = fileCode.c_str();

		GLuint shader;
		GLint success;

		switch (shaderType)
		{
		case ShaderType::VERTEX:
			shader = glCreateShader(GL_VERTEX_SHADER);
			break;
		case ShaderType::FRAGMENT:
			shader = glCreateShader(GL_FRAGMENT_SHADER);
			break;
		case ShaderType::TESSELLATION:
			shader = glCreateShader(GL_ARB_tessellation_shader);
			break;
		case ShaderType::GEOMETRY:
			shader = glCreateShader(GL_GEOMETRY_SHADER);
			break;
		}

		glShaderSource(shader, 1, &shaderCode, NULL);
		glCompileShader(shader);

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			LogManager::LogMessage(LogMessageType::ERROR, "Shader Compilation Failed", __FILE__, __LINE__);
		}

		this->program = glCreateProgram();
		glAttachShader(this->program, shader);
		glLinkProgram(this->program);

		glGetProgramiv(this->program, GL_LINK_STATUS, &success);
		if (!success)
		{
			LogManager::LogMessage(LogMessageType::ERROR, "Shader Linking Failed", __FILE__, __LINE__);
		}

		glDeleteShader(shader);
	}

	void Shader::UseShader()
	{
		glUseProgram(this->program);
	}
}
