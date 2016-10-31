#include "Engine.h"

#include "Timer.h"

namespace DRE
{
	Engine* Engine::m_pEngineInstance(nullptr);
	EngineState Engine::m_EngineState(EngineState::INVALID);

	Engine* Engine::GetInstance()
	{
		if (m_pEngineInstance == nullptr)
		{
			m_pEngineInstance = new Engine();
		}
		return m_pEngineInstance;
	}

	bool Engine::Run()
	{
		if (!this->Initialize())
		{
			return false;
		}

		Timer t;
		t.Start();

		m_EngineState = EngineState::RUNNING;
		
		while (m_bIsRunning)
		{
			t.UpdateFrameTicks();
			Update();
			Render();
			SDL_Delay(t.GetSleepTime(m_TargetFPS));
		}

		Shutdown();
		return true;
	}

	Engine::Engine()
		: m_bIsRunning(false)
	{
		m_EngineState = EngineState::CONSTRUCTING;
	}

	Engine::~Engine()
	{
		m_EngineState = EngineState::DESTROYING;
	}

	bool Engine::Initialize()
	{
		m_EngineState = EngineState::INITIALIZING;
		m_bIsRunning = true;
		return true;
	}

	bool Engine::Update()
	{
		return true;
	}

	bool Engine::Render()
	{
		return true;
	}

	void Engine::Shutdown()
	{
		m_EngineState = EngineState::SHUTTINGDOWN;
	}
}
