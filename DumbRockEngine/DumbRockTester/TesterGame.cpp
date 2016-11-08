#include "TesterGame.h"

#include <iostream>

namespace DRE
{
	TesterGame::TesterGame()
		: GameEngine()
	{
		this->targetFPS = 60;
	}

	TesterGame::~TesterGame()
	{

	}

	void TesterGame::StartGame()
	{
		isRunning = this->OnStart();

		while (isRunning)
		{
			Timer t;
			t.UpdateFrameTicks();

			this->Update();
			this->LateUpdate();

			this->PreRender();
			this->Render();
			this->PostRender();

			SDL_Delay(targetFPS);
		}

		this->OnEnd();
	}

	bool TesterGame::OnStart()
	{
		std::cout << "DRE Game Started" << std::endl;

		m_pWindow = new Window("DumbRockEngine - Test Game");
		m_pWindow->SetWindowSize(1024, 512);
		if (!m_pWindow->Initialize())
		{
			return false;
		}

		m_pAbstractRenderer = new OpenGLRenderer();
		if (!m_pAbstractRenderer->Initialize())
		{
			return false;
		}

		return true;
	}

	void TesterGame::OnEnd()
	{
		std::cout << "DRE Game Ended" << std::endl;
	}

	void TesterGame::Update()
	{
		std::cout << "DRE Game Updated" << std::endl;
	}

	void TesterGame::LateUpdate()
	{
		std::cout << "DRE Game Late Updated" << std::endl;
	}

	void TesterGame::PreRender()
	{
		std::cout << "DRE Game Pre Rendered" << std::endl;
		m_pAbstractRenderer->ClearRenderer(this->m_pWindow);
	}

	void TesterGame::Render()
	{
		std::cout << "DRE Game Rendered" << std::endl;
	}

	void TesterGame::PostRender()
	{
		std::cout << "DRE Game Post Rendered" << std::endl;
	}
}
