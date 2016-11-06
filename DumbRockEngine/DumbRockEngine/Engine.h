#ifndef _ENGINE_H
#define _ENGINE_H

#pragma once

#include "DRE_Game.h"

#include "Window.h"
#include "OpenGLRenderer.h"

namespace DRE
{
	enum EngineState
	{
		INVALID,
		CONSTRUCTING,
		INITIALIZING,
		RUNNING,
		SHUTTINGDOWN,
		DESTROYING
	};

	class Engine
	{
	public:
		static Engine* GetInstance();

		bool Run();

		void SetTargetFPS(UINT targetFPS);

	private:
		Engine();
		~Engine();

		bool Initialize();
		bool Update();
		bool Render();
		void Shutdown();

		UINT m_TargetFPS;
		bool m_bIsRunning;

		DRE_Game* m_pDREGame;
		Window* m_pWindow;
		AbstractRenderer* m_pAbstractRenderer;

		static Engine* m_pEngineInstance;
		static EngineState m_EngineState;
	};
}

#endif