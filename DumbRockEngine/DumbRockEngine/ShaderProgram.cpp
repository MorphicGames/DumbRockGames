#include "ShaderProgram.h"

#include "LogManager.h"

namespace DRE
{
	ShaderProgram::ShaderProgram(ShaderManager* shaderManager)
		: m_pShaderManager(shaderManager)
	{
		this->m_Program = glCreateProgram();
	}

	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(this->m_Program);
	}

	void ShaderProgram::AttachShader(const Shader& shader)
	{
		glAttachShader(this->m_Program, shader.GetShader());
	}

	void ShaderProgram::AttachShader(const std::string& shaderName)
	{
		//Need to fully implement ShaderManager before can complete
	}

	void ShaderProgram::DetachShader(const Shader& shader)
	{
		glDetachShader(this->m_Program, shader.GetShader());
	}

	void ShaderProgram::DetachShader(const std::string& shaderName)
	{
		//Need to fully implement ShaderManager before can complete
	}

	void ShaderProgram::LinkProgram()
	{
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
