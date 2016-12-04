#ifndef _MATERIALMANAGER_H
#define _MATERIALMANAGER_H

#pragma once

#include "ResourceManager.h"

#define MATERIAL_MANAGER DRE::MaterialManager::Instance()

class Material;

namespace DRE
{
	class MaterialManager
	{
	private:
		MaterialManager();
		ResourceManager<Material>* m_MaterialList;
	public:
		static MaterialManager& Instance();
	};
}

#endif