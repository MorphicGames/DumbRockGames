#include "MaterialManager.h"

namespace DRE
{
	MaterialManager* MaterialManager::m_pInstance = nullptr;

	MaterialManager* MaterialManager::GetInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new MaterialManager();
		}
		return m_pInstance;
	}

	MaterialManager::MaterialManager()
	{
		m_MaterialList = new ResourceManager<Material>();
	}

	MaterialManager::~MaterialManager()
	{

	}
}
