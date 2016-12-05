#ifndef _GAME_H
#define _GAME_H

#pragma once

#include "DRE_defines.h"
#include "DRE_typedef.h"

#include "LogManager.h"
#include "Timer.h"
#include "Window.h"

#include "ShaderProgram.h"

#include "OpenGLRenderer.h"

#include "InputManager.h"
#include "MaterialManager.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include "SpriteManager.h"
#include "TextureManager.h"

#define GAME DRE::Game::Instance()

class Scene;

namespace DRE
{
	class Game
	{
	private:
		void EngineUpdate(const F32 timeStep);
		void EngineRender();

	public:
		static Game& Instance();

		void RunGame();
		void GameLoop();
		void LoadScene(Scene* scene);

		virtual void UpdateGame(const F32 deltaTime);
		virtual void RenderGame();

		Timer* gameTimer;
		Window* gameWindow;
		AbstractRenderer* renderer;

		Scene* currentScene;
		Scene* nextScene;

	protected:
		explicit Game();
		virtual ~Game();
		
		bool InitializeEngine();
		virtual bool InitializeGame();

		void PreRender();
		void PostRender();

		void DestroyGame();

		F32 fps;
		F32 totalTime, lastUpdateTime, timeSinceLastUpdate;
		F32 deltaTime;

		bool isRunning;
		bool canLoadNewScene;
	};
}

#endif