#include "ModelManager.h"

namespace DRE
{
	ModelManager& ModelManager::Instance()
	{
		static ModelManager *instance = new ModelManager();
		return *instance;
	}

	ModelManager::ModelManager()
	{
		m_ModelList = new ResourceManager<Model>();
	}

	void ModelManager::AddModel(const std::string& modelName, Model* model)
	{
		m_ModelList->AddResource(modelName, model);
	}

	Model* ModelManager::GetModel(const std::string& modelName)
	{
		return m_ModelList->GetResource(modelName);
	}
}
