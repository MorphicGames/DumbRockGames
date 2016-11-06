#include "ShaderComponent.h"

#include <iostream>
#include <string>
#include <fstream>

namespace DRE
{
	ShaderComponent::ShaderComponent(const std::string& shaderFilename, const std::string& shaderName, ShaderType type)
	{
		m_sourceFilename = shaderFilename;
		m_sourceResource = shaderName;
	}

	ShaderComponent::~ShaderComponent()
	{
		DetachFromAllPrograms();
		RemoveFromGPU();
		delete shaderReference;
	}

	std::string ShaderComponent::GetCompileMessage() const
	{
		std::string result;
		int compileStatus = 0;

		GLuint shaderObj = shaderReference->getOpenGLReference();
		GLenum shadeType;
		switch (this->m_ShaderType)
		{
		case ShaderType::VERTEX:
		{
			shadeType = GL_VERTEX_SHADER;
			break;
		}
		case ShaderType::FRAGMENT:
		{
			shadeType = GL_FRAGMENT_SHADER;
			break;
		}
		case ShaderType::GEOMETRY:
		{
			shadeType = GL_GEOMETRY_SHADER;
			break;
		}
		case ShaderType::TESSELLATION:
		{
			shadeType = NULL;
			break;
		}
		}

		glGetShaderiv(shaderObj, GL_COMPILE_STATUS, &compileStatus);
		if (compileStatus == GL_FALSE)
		{
			int loglength = 0;
			glGetShaderiv(shaderObj, GL_COMPILE_STATUS, &loglength);
			if (loglength > 0)
			{
				char* msg = new char[loglength];
				int charsCopied = 0;
				glGetShaderInfoLog(shaderObj, loglength, &charsCopied, msg);
				result = msg;
				delete[] msg;
			}
		}

		return result;
	}

	void ShaderComponent::LoadShaderSource()
	{
		std::string tmp;
		std::string line;
		std::ifstream shader;

		shader.open(m_sourceFilename, std::ios::in);

		if (shader.is_open())
		{
			while (std::getline(shader, line))
			{
				tmp += line + '\n';
			}
			shader.close();
		}
		else
		{
			std::cout << "Shader with name: " + m_sourceResource + " failed to be opened" << std::endl;
			tmp = "NULL";
		}

		m_shaderSource = tmp;

		GLenum shadeType;
		switch (this->m_ShaderType)
		{
		case ShaderType::VERTEX:
		{
			shadeType = GL_VERTEX_SHADER;
			break;
		}
		case ShaderType::FRAGMENT:
		{
			shadeType = GL_FRAGMENT_SHADER;
			break;
		}
		case ShaderType::GEOMETRY:
		{
			shadeType = GL_GEOMETRY_SHADER;
			break;
		}
		case ShaderType::TESSELLATION:
		{
			shadeType = NULL;
			break;
		}
		}

		if (shaderReference->IsNull())
		{
			GLuint shRef = glCreateShader(shadeType);
			shaderReference->setOpenGLReference(shRef);
		}

		GLchar** str = new GLchar*[1];
		str[0] = new char[m_shaderSource.size() + 1];
		std::strcpy(str[0], m_shaderSource.c_str());
		str[0][m_shaderSource.size()] = '\0';
		glShaderSource(shaderReference->getOpenGLReference(), 1, str, NULL);

		delete[] str[0];
		delete[] str;
	}

	void ShaderComponent::CompileShader()
	{
		if (m_shaderSource.size() == 0)
		{
			//Do Throw Exception Here
		}

		GLenum shadeType;
		switch (this->m_ShaderType)
		{
		case ShaderType::VERTEX:
		{
			shadeType = GL_VERTEX_SHADER;
			break;
		}
		case ShaderType::FRAGMENT:
		{
			shadeType = GL_FRAGMENT_SHADER;
			break;
		}
		case ShaderType::GEOMETRY:
		{
			shadeType = GL_GEOMETRY_SHADER;
			break;
		}
		case ShaderType::TESSELLATION:
		{
			shadeType = NULL;
			break;
		}
		}

		if (shaderReference->IsNull())
		{
			GLuint shRef = glCreateShader(shadeType);
			shaderReference->setOpenGLReference(shRef);
		}

		GLchar** str = new GLchar*[1];
		str[0] = new char[m_shaderSource.size() + 1];
		std::strcpy(str[0], m_shaderSource.c_str());
		str[0][m_shaderSource.size()] = '\0';
		glShaderSource(shaderReference->getOpenGLReference(), 1, str, NULL);

		delete[] str[0];
		delete[] str;

		glCompileShader(shaderReference->getOpenGLReference());
		std::string msg = GetCompileMessage();
		if (msg.size() > 0)
		{
			//Do Throw Corrupt Exception Here
		}
		canRun = true;
	}

	void ShaderComponent::MakeRunnable()
	{
		if (m_shaderSource.size() == 0)
		{
			if (m_sourceFilename.size() == 0)
			{
				//Throw Corrupt Exception
			}
			LoadShaderSource();
		}
		CompileShader();
	}

	void ShaderComponent::RemoveFromGPU()
	{
		if (canRun && (!shaderReference->IsNull()))
		{
			GLuint shaderRef = shaderReference->getOpenGLReference();
			glDeleteShader(shaderRef);
			shaderReference->Nullify();
			canRun = false;
		}
	}
}