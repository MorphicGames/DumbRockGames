#include "ShaderProgram.h"

#include "LogManager.h"

namespace DRE
{
	ShaderProgram::ShaderProgram()
	{
		LogManager::LogMessage(LogMessageType::INFO, "Created Shader Program", __FILE__, __LINE__);
		this->m_Program = glCreateProgram();
	}

	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(this->m_Program);
	}

	GLuint ShaderProgram::GetProgram() const
	{
		return m_Program;
	}

	void ShaderProgram::AttachShader(const Shader& shader)
	{
		LogManager::LogMessage(LogMessageType::INFO, "Attaching Shader to Shader Program", __FILE__, __LINE__);
		glAttachShader(this->m_Program, shader.GetShader());
	}

	void ShaderProgram::AttachShader(const std::string& shaderName)
	{
		Shader* tmp = SHADER_MANAGER.GetShader(shaderName);
		LogManager::LogMessage(LogMessageType::INFO, "Attaching Shader to Shader Program", __FILE__, __LINE__);
		glAttachShader(this->m_Program, tmp->GetShader());
	}

	void ShaderProgram::DetachShader(const Shader& shader)
	{
		LogManager::LogMessage(LogMessageType::INFO, "Detaching Shader from Shader Program", __FILE__, __LINE__);
		glDetachShader(this->m_Program, shader.GetShader());
	}

	void ShaderProgram::DetachShader(const std::string& shaderName)
	{
		Shader* tmp = SHADER_MANAGER.GetShader(shaderName);
		LogManager::LogMessage(LogMessageType::INFO, "Detaching Shader from Shader Program", __FILE__, __LINE__);
		glDetachShader(this->m_Program, tmp->GetShader());
	}

	void ShaderProgram::LinkProgram()
	{
		LogManager::LogMessage(LogMessageType::INFO, "Linking Shader Program", __FILE__, __LINE__);

		GLint success;

		glLinkProgram(this->m_Program);

		glGetProgramiv(this->m_Program, GL_LINK_STATUS, &success);
		if (!success)
		{
			LogManager::LogMessage(LogMessageType::ERROR, "Shader Linking Failed", __FILE__, __LINE__);
			GLint infoLogLength;
			glGetProgramiv(this->m_Program, GL_INFO_LOG_LENGTH, &infoLogLength);
			if (infoLogLength > 1)
			{
				GLchar* infoLog = (GLchar*)malloc(infoLogLength + 1);
				glGetProgramInfoLog(this->m_Program, infoLogLength, &infoLogLength, infoLog);
				LogManager::LogMessage(LogMessageType::ERROR, infoLog, __FILE__, __LINE__);
				free(infoLog);
			}
		}

		viewLocation = glGetUniformLocation(this->m_Program, "view");
		projectionLocation = glGetUniformLocation(this->m_Program, "projection");
	}

	void ShaderProgram::UseProgram()
	{
		LogManager::LogMessage(LogMessageType::INFO, "Using Shader Program", __FILE__, __LINE__);
		glUseProgram(this->m_Program);
	}
}
