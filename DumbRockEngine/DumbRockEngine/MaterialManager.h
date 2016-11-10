#ifndef _MATERIALMANAGER_H
#define _MATERIALMANAGER_H

#pragma once

#include "ResourceManager.h"

class Material;

namespace DRE
{
	class MaterialManager
	{
	private:
		MaterialManager();
		~MaterialManager();

		ResourceManager<Material>* m_MaterialList;

		static MaterialManager* m_pInstance;

	public:
		static MaterialManager* GetInstance();
	};
}

#endif