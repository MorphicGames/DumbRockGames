#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#pragma once

#include <vector>

//#include "Scene.h"

#include "Component.h"
#include "Transform.h"
#include "DRE_typedef.h"

class Scene;

namespace DRE
{
	class GameObject
	{
	public:
		explicit GameObject(Scene* scene, std::string name = "");
		virtual ~GameObject();

		virtual void Update(const F32 deltaTime);
		virtual void PreRender();
		virtual void Render();

		void AddChild(GameObject* gameObject);
		void RemoveChild(GameObject* gameObject);
		void RemoveChild(std::string name);
		void ClearAllChildren();

		GameObject* GetChild(std::string name);

		void AddComponent(Component* component);
		bool HasComponent(Component* component);
		void RemoveComponent(Component* component);

		template<typename T> T* GetComponent();

		void AddTag(std::string tag);
		bool HasTag(std::string tag);
		void RemoveTag(std::string tag);

		inline bool CheckEnabled() const {
			return isEnabled;
		}

		inline void SetEnabled(bool b) {
			isEnabled = b;
		}

		inline std::string GetName() const {
			return name;
		}

		inline void SetName(const std::string& name) {
			this->name = name;
		}

		std::vector<std::string> tags;
		std::vector<Component*> componentList;
		std::vector<GameObject*> childObjects;

		bool isEnabled;

		GameObject* gameObject;

		Transform transform;

		Scene* scene;

	protected:
		std::string name;

	};
}

#endif
