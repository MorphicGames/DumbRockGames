#ifndef _ENGINE_H
#define _ENGINE_H

#pragma once

#include "Window.h"

class DRE_Game;

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

	private:
		Engine();
		~Engine();

		bool Initialize();
		bool Update();
		bool Render();
		void Shutdown();

		DRE_Game* m_pDREGame;

		static Engine* m_pEngineInstance;
		static EngineState m_EngineState;
	};
}

#endif