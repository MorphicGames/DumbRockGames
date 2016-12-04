#ifndef _SCENE_H
#define _SCENE_H

#pragma once

#include <string>
#include <memory>

#include "Camera.h"
#include "GameObject.h"
#include "DRE_typedef.h"

#define ROOT_NAME "RootNode"


namespace DRE
{
	class Game;

	class Scene
	{
		friend class Game;
	public:
		Scene();
		virtual ~Scene();

		virtual void InitializeScene() = 0;
		virtual void Update(const F32 timeStep);
		virtual void Render();

		void SetCamera(Camera* camera);

		void AddSceneNode(GameObject* gameObject);
		void RemoveSceneNode(const std::string& gameObjectName);
		void ClearAllSceneNodes();

		GameObject* FindGameObject(const std::string& gameObjectName);

		inline std::string GetSceneName() const {
			return sceneName;
		}

		inline void SetSceneName(const std::string& name) {
			sceneName = name;
		}

		I32 GetSceneSize() const;

		Camera* mainCamera;
		Camera* currentCamera;

	protected:
		std::string sceneName;

		std::unique_ptr<GameObject> rootNode;
		friend std::default_delete<GameObject>;
	};
}

#endif