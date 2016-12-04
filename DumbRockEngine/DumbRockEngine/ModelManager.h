#ifndef _MODELMANAGER_H
#define _MODELMANAGER_H

#pragma once

#include "ResourceManager.h"

#include "Model.h"

#define MODEL_MANAGER DRE::ModelManager::Instance()

namespace DRE
{
	class ModelManager
	{
	private:
		ModelManager();
		ResourceManager<Model>* m_ModelList;
	public:
		static ModelManager& Instance();
		void AddModel(const std::string& modelName, Model* model);
		Model* GetModel(const std::string& modelName);
	};
}

#endif