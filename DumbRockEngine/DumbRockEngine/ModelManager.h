#ifndef _MODELMANAGER_H
#define _MODELMANAGER_H

#pragma once

#include "ResourceManager.h"

#include "Model.h"

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

		void AddModel(const std::string& modelName, Model* model);

		Model* GetModel(const std::string& modelName);
	};
}

#endif