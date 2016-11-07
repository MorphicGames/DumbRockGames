#include "TesterGame.h"

namespace DRE
{
	TesterGame::TesterGame()
		: GameEngine()
	{

	}

	TesterGame::~TesterGame()
	{

	}

	void TesterGame::StartGame()
	{
		OnStart();
	}

	void TesterGame::OnStart()
	{
		m_pWindow = new Window("DumbRockEngine - Test Game");
		m_pWindow->SetWindowSize(1024, 512);
		m_pWindow->Initialize();
	}

	void TesterGame::OnEnd()
	{

	}

	void TesterGame::Update()
	{

	}

	void TesterGame::LateUpdate()
	{

	}

	void TesterGame::PreRender()
	{

	}

	void TesterGame::Render()
	{

	}

	void TesterGame::PostRender()
	{

	}
}
