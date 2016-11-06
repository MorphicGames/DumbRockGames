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

	void Engine::SetTargetFPS(UINT targetFPS)
	{
		this->m_TargetFPS = targetFPS;
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

		if (m_pWindow->Initialize())
		{
			return false;
		}

		if (m_pAbstractRenderer->Initialize())
		{
			return false;
		}

		if (m_pDREGame->Initialize())
		{
			return false;
		}

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
