#include "TesterGame.h"

namespace DRE
{
	TesterGame::TesterGame()
		: GameEngine()
	{
		this->targetFPS = 60;

		LogManager::Initialize();

		LogManager::LogMessage(LogMessageType::INFO, "Created Game Engine", __FILE__, __LINE__);
	}

	TesterGame::~TesterGame()
	{
		LogManager::LogMessage(LogMessageType::INFO, "Destroying Game Engine", __FILE__, __LINE__);
		OnEnd();
	}

	void TesterGame::StartGame()
	{
		isRunning = this->OnStart();

		Timer t;
		t.Start();

		while (isRunning)
		{
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
		LogManager::LogMessage(LogMessageType::INFO, "Starting Game Engine", __FILE__, __LINE__);

		m_pModelManager = ModelManager::GetInstance();
		m_pTextureManager = TextureManager::GetInstance();
		m_pMaterialManager = MaterialManager::GetInstance();
		m_pShaderManager = ShaderManager::GetInstance();

		m_pWindow = new Window("DumbRockEngine - Test Game");
		m_pWindow->SetWindowSize(1024, 512);
		if (!m_pWindow->Initialize())
		{
			LogManager::LogMessage(LogMessageType::ERROR, "Failed to Initialize Window", __FILE__, __LINE__);
			return false;
		}

		m_pAbstractRenderer = new OpenGLRenderer();
		m_pAbstractRenderer->SetClearColour(new Colour(0.0f, 0.0f, 0.0f, 1.0f));
		if (!m_pAbstractRenderer->Initialize())
		{
			LogManager::LogMessage(LogMessageType::ERROR, "Failed to Initialize Renderer", __FILE__, __LINE__);
			return false;
		}

		m_pShaderManager->AddShader("TestVertexShader", new Shader("TestVertexShader.vert", ShaderType::VERTEX));
		m_pShaderManager->AddShader("TestFragmentShader", new Shader("TestFragmentShader.frag", ShaderType::FRAGMENT));

		m_pShaderProgram = new ShaderProgram(this->m_pShaderManager);
		m_pShaderProgram->AttachShader("TestVertexShader");
		m_pShaderProgram->AttachShader("TestFragmentShader");
		m_pShaderProgram->LinkProgram();

		m_pModelManager->AddModel("TestModel", new Model("Assets/TestModel"));

		return true;
	}

	void TesterGame::OnEnd()
	{
		LogManager::LogMessage(LogMessageType::INFO, "Ending Game Engine", __FILE__, __LINE__);
	}

	void TesterGame::Update()
	{
		SDL_Event SDLEvent;

		while (SDL_PollEvent(&SDLEvent))
		{
			switch (SDLEvent.type)
			{
				case SDL_EventType::SDL_QUIT:
				{
					isRunning = false;
					return;
				}
				default:
				{
					break;
				}
			}
		}
	}

	void TesterGame::LateUpdate()
	{

	}

	void TesterGame::PreRender()
	{
		m_pAbstractRenderer->ClearRenderer(this->m_pWindow);
	}

	void TesterGame::Render()
	{
		m_pShaderProgram->UseProgram();
	}

	void TesterGame::PostRender()
	{

	}
}
