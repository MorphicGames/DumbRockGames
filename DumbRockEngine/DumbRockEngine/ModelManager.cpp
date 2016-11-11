#include "ModelManager.h"

namespace DRE
{
	ModelManager* ModelManager::m_pInstance = nullptr;

	ModelManager* ModelManager::GetInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new ModelManager();
		}
		return m_pInstance;
	}

	ModelManager::ModelManager()
	{
		m_ModelList = new ResourceManager<Model>();
	}

	ModelManager::~ModelManager()
	{

	}
}