#include "ShaderManager.h"

namespace DRE
{
	ShaderManager* ShaderManager::m_pInstance = nullptr;

	ShaderManager* ShaderManager::GetInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new ShaderManager();
		}
		return m_pInstance;
	}

	ShaderManager::ShaderManager()
	{
		m_ShaderList = new ResourceManager<Shader>();
	}

	ShaderManager::~ShaderManager()
	{

	}

	void ShaderManager::AddShader(const std::string& shaderName, Shader* shader)
	{
		this->m_ShaderList->AddResource(shaderName, shader);
	}
}
