#include "MaterialManager.h"

namespace DRE
{
	MaterialManager& MaterialManager::Instance()
	{
		static MaterialManager *instance = new MaterialManager();
		return *instance;
	}

	MaterialManager::MaterialManager()
	{
		m_MaterialList = new ResourceManager<Material>();
	}
}
