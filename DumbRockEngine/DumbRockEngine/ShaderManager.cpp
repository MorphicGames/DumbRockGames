#include "ShaderManager.h"

namespace DRE
{
	ShaderManager& ShaderManager::Instance()
	{
		static ShaderManager *instance = new ShaderManager();
		return *instance;
	}

	ShaderManager::ShaderManager()
	{
		m_ShaderList = new ResourceManager<Shader>();
	}

	void ShaderManager::AddShader(const std::string& shaderName, Shader* shader)
	{
		m_ShaderList->AddResource(shaderName, shader);
	}

	Shader* ShaderManager::GetShader(const std::string& shaderName)
	{
		return m_ShaderList->GetResource(shaderName);
	}
}
