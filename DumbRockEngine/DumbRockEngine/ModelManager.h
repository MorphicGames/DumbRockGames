#ifndef _MODELMANAGER_H
#define _MODELMANAGER_H

#pragma once

#include "ResourceManager.h"

class Model;

namespace DRE
{
	class ModelManager
	{
	private:
		ModelManager();
		~ModelManager();

		ResourceManager<Model>* m_ModelList;

		static ModelManager* m_pInstance;

	public:
		static ModelManager* GetInstance();
	};
}

#endif