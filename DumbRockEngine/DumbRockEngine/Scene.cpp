#include "Scene.h"

#include <vector>

namespace DRE
{
	Scene::Scene()
	{
		rootNode.reset(nullptr);

		rootNode.reset(new GameObject(this, ROOT_NAME));

		//rootNode->transform.position = ORIGIN;

		mainCamera = currentCamera = nullptr;
		mainCamera = new Camera(this);
		mainCamera->SetName("MainCamera");
		mainCamera->AddTag("Camera");
		
		SetCamera(mainCamera);
	}

	Scene::~Scene()
	{
		ClearAllSceneNodes();
	}

	void Scene::SetCamera(Camera* camera)
	{
		currentCamera = camera;
	}

	void Scene::Update(const F32 timeStep)
	{
		mainCamera->Update(timeStep);

		std::vector<GameObject*>::iterator iter;
		for (iter = rootNode->childObjects.begin(); iter != rootNode->childObjects.end(); iter++)
		{
			GameObject* tmp = (*iter);

			if (tmp && tmp->CheckEnabled)
			{
				tmp->Update(timeStep);
			}
		}
	}

	void Scene::Render()
	{
		mainCamera->Render();

		std::vector<GameObject*>::iterator iter;
		for (iter = rootNode->childObjects.begin(); iter != rootNode->childObjects.end(); iter++)
		{
			GameObject* tmp = (*iter);

			if (tmp && tmp->CheckEnabled() && !tmp->HasTag("Camera"))
			{
				tmp->Render();
			}
		}
	}

	void Scene::AddSceneNode(GameObject* gameObject)
	{
		std::string test = gameObject->GetName();

		if (test == "")
		{
			std::string newName = "GameObject(" + std::to_string(GetSceneSize()) + ")";
		}
		rootNode->AddChild(gameObject);
	}

	void Scene::RemoveSceneNode(const std::string& gameObjectName)
	{
		rootNode->RemoveChild(gameObjectName);
	}

	void Scene::ClearAllSceneNodes()
	{
		rootNode->ClearAllChildren();
	}

	GameObject* Scene::FindGameObject(const std::string& name)
	{
		return rootNode->GetChild(name);
	}

	I32 Scene::GetSceneSize() const {
		I32 total = rootNode->childObjects.size();
		return total;
	}
}
