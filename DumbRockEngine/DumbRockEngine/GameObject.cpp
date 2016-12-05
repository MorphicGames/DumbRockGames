#include "GameObject.h"

#include "LogManager.h"
#include "DRE_defines.h"

namespace DRE
{
	GameObject::GameObject(Scene* scene, std::string name)
		: gameObject(this)
	{
		if (name == "")
		{
			SetName("");
		}
		else
		{
			SetName(name);
		}

		transform.Reset();
		SetEnabled(true);

		this->scene = scene;
		this->scene->AddSceneNode(this);
	}

	GameObject::~GameObject()
	{
		if (componentList.size() > 0)
		{
			for (int i = 0; i < componentList.size(); i++)
			{
				P_DELETE(componentList[i]);
			}
		}
		componentList.clear();
	}

	void GameObject::AddChild(GameObject* gameObject)
	{
		childObjects.push_back(gameObject);
	}

	void GameObject::RemoveChild(GameObject* gameObject)
	{
		std::vector<GameObject*>::iterator iter;
		for (iter = childObjects.begin(); iter != childObjects.end(); iter++)
		{
			if (*iter == gameObject) {
				delete *iter;
				*iter = nullptr;
				return;
			}
		}
		LogManager::LogMessage(LogMessageType::WARNING, "GameObject is not a child", __FILE__, __LINE__);
	}

	void GameObject::RemoveChild(std::string name)
	{
		std::vector<GameObject*>::iterator iter;
		for (iter = childObjects.begin(); iter != childObjects.end(); iter++)
		{
			GameObject* temp = *iter;
			if (temp->GetName() == name)
			{
				delete *iter;
				childObjects.erase(iter);
				return;
			}
		}
		childObjects.shrink_to_fit();
	}

	void GameObject::ClearAllChildren()
	{
		if (childObjects.size() > 0)
		{
			std::vector<GameObject*>::iterator iter;
			for (iter = childObjects.begin(); iter != childObjects.end(); iter++)
			{
				delete *iter;
				*iter = nullptr;
			}
		}
		childObjects.clear();
	}

	GameObject* GameObject::GetChild(std::string name)
	{
		std::vector<GameObject*>::iterator iter;
		for (iter = childObjects.begin(); iter != childObjects.end(); iter++)
		{
			GameObject* temp = *iter;
			if (temp->GetName() == name)
			{
				return temp;
			}
		}
		return nullptr;
	}

	void GameObject::AddComponent(Component* c)
	{
		bool checkComp = HasComponent(c);

		if (!checkComp)
		{
			componentList.push_back(c);
			return;
		}
	}

	bool GameObject::HasComponent(Component* c)
	{
		if (componentList.size() > 0)
		{
			for (int i = 0; i < componentList.size(); i++)
			{
				Component* temp = componentList[i];
				if (temp->mtype == c->mtype)
				{
					return true;
				}
			}
		}
		return false;
	}

	void GameObject::RemoveComponent(Component* component)
	{

	}

	template<typename T> T* GameObject::GetComponent()
	{
		for (int i = 0; i < componentList.size(); i++)
		{
			if (typeid(*componentList[i]).name() == typeid(T).name())
			{
				return dynamic_cast<T*>(componentList[i]);
			}
		}
		return nullptr;
	}

	void GameObject::AddTag(std::string tag)
	{
		bool checkTag = HasTag(tag);

		if (!checkTag)
		{
			tags.push_back(tag);
			return;
		}
	}

	bool GameObject::HasTag(std::string tag)
	{
		for (int i = 0; i < tags.size(); i++)
		{
			if (tags[i] == tag)
				return true;
		}
		return false;
	}

	void GameObject::RemoveTag(std::string tag)
	{
		bool checkTag = HasTag(tag);

		if (!checkTag)
			return;

		for (int i = 0; i < tags.size(); i++)
		{
			if (tags[i] == tag) {

			}
		}
		tags.shrink_to_fit();
	}

	void GameObject::Update(const F32 deltaTime)
	{

	}

	void GameObject::Render()
	{

	}

	void GameObject::PreRender()
	{

	}
}