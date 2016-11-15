#include "ShaderProgram.h"

#include "LogManager.h"

namespace DRE
{
	ShaderProgram::ShaderProgram(ShaderManager* shaderManager)
		: m_pShaderManager(shaderManager)
	{
		LogManager::LogMessage(LogMessageType::INFO, "Created Shader Program", __FILE__, __LINE__);
		this->m_Program = glCreateProgram();
	}

	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(this->m_Program);
	}

	void ShaderProgram::AttachShader(const Shader& shader)
	{
		LogManager::LogMessage(LogMessageType::INFO, "Attaching Shader to Shader Program", __FILE__, __LINE__);
		glAttachShader(this->m_Program, shader.GetShader());
	}

	void ShaderProgram::AttachShader(const std::string& shaderName)
	{
		//Need to fully implement ShaderManager before can complete
	}

	void ShaderProgram::DetachShader(const Shader& shader)
	{
		LogManager::LogMessage(LogMessageType::INFO, "Detaching Shader from Shader Program", __FILE__, __LINE__);
		glDetachShader(this->m_Program, shader.GetShader());
	}

	void ShaderProgram::DetachShader(const std::string& shaderName)
	{
		//Need to fully implement ShaderManager before can complete
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
		}
	}

	void ShaderProgram::UseProgram()
	{
		glUseProgram(this->m_Program);
	}
}
