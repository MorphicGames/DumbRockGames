#include "Shader.h"

#include "LogManager.h"

#include <glew.h>

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

		GLint success;

		switch (shaderType)
		{
		case ShaderType::VERTEX:
			this->m_Shader = glCreateShader(GL_VERTEX_SHADER);
			break;
		case ShaderType::FRAGMENT:
			this->m_Shader = glCreateShader(GL_FRAGMENT_SHADER);
			break;
		case ShaderType::TESSELLATION:
			this->m_Shader = glCreateShader(GL_ARB_tessellation_shader);
			break;
		case ShaderType::GEOMETRY:
			this->m_Shader = glCreateShader(GL_GEOMETRY_SHADER);
			break;
		}

		glShaderSource(this->m_Shader, 1, &shaderCode, NULL);
		glCompileShader(this->m_Shader);

		glGetShaderiv(this->m_Shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			LogManager::LogMessage(LogMessageType::ERROR, "Shader Compilation Failed", __FILE__, __LINE__);
		}
	}

	Shader::~Shader()
	{
		glDeleteShader(this->m_Shader);
	}

	GLuint Shader::GetShader() const
	{
		return this->m_Shader;
	}
}
