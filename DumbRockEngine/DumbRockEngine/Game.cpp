#include "Game.h"

#include "Scene.h"

namespace DRE
{
	//FIX
	Game* Game::instance = nullptr;
	Game* Game::Instance()
	{
		if (instance == nullptr)
		{
			instance = new Game();
		}

	//	static Game *instance = new Game(); //Inifinte loop
		return instance;
	}

	Game::Game()
	{
		isRunning = true;
		canLoadNewScene = false;
		fps = 0.0f;
		totalTime = 0.0f;
		deltaTime = 0.0f;
		lastUpdateTime = 0.0f;
		timeSinceLastUpdate = 0.0f;

		gameWindow = nullptr;
		currentScene = nullptr;
		nextScene = nullptr;
	}

	Game::~Game()
	{
		DestroyGame();
	}

	bool Game::InitializeEngine()
	{
		SDL_Init(SDL_INIT_EVERYTHING);

		gameTimer = new Timer();
		gameTimer->Start();

		gameWindow = new Window("DumbRockEngine");
		gameWindow->SetWindowSize(1600, 900);
		gameWindow->Initialize();

		renderer = new OpenGLRenderer();

		fps = 60.0f;

		LogManager::LogMessage(LogMessageType::INFO, "Game Engine Initialized", __FILE__, __LINE__);
		return true;
	}

	void Game::LoadScene(Scene* scene)
	{
		if (nextScene != nullptr)
		{
			delete nextScene;
		}

		nextScene = scene;
		canLoadNewScene = true;
	}

	void Game::UpdateGame(const F32 deltaTime)
	{

	}

	void Game::RenderGame()
	{

	}

	bool Game::InitializeGame()
	{
		return false;
	}

	void Game::DestroyGame()
	{
		if (currentScene) {
			P_DELETE(currentScene);
		}

		P_DELETE(gameTimer);
		P_DELETE(renderer);
		P_DELETE(gameWindow);
	}

	void Game::RunGame()
	{
		bool init = InitializeEngine();

		if (!init)
		{
			LogManager::LogMessage(LogMessageType::FATAL_ERROR, "Engine Initialization Failed", __FILE__, __LINE__);
			getchar();
			return;
		}
		else
		{
			InitializeGame();
			GameLoop();
		}
		DestroyGame();
	}

	void Game::GameLoop()
	{
		SDL_Event SDLevent;

		while (isRunning)
		{
			gameTimer->UpdateFrameTicks();
			deltaTime = gameTimer->GetDeltaTime();

			while (SDL_PollEvent(&SDLevent))
			{
				INPUT_MANAGER.ProcessInput(SDLevent);

				if (SDLevent.type == SDL_QUIT || INPUT_MANAGER.IsKeyDown(SDLK_ESCAPE))
				{
					LogManager::LogMessage(LogMessageType::INFO, "Exit Game", __FILE__, __LINE__);
					isRunning = false;
				}
			}
			SDL_PumpEvents();

			INPUT_MANAGER.Update();

			EngineUpdate(deltaTime);
			EngineRender();

			totalTime += deltaTime;
			unsigned int sleep = gameTimer->GetSleepTime(fps);
			SDL_Delay(sleep);
		}
	}

	void Game::EngineUpdate(const F32 timeStep)
	{
		if (canLoadNewScene)
		{
			canLoadNewScene = false;

			if (currentScene)
			{
				delete currentScene;
			}

			currentScene = nextScene;

			currentScene->InitializeScene();
		}

		if (currentScene) {
			currentScene->Update(timeStep);
		}

		UpdateGame(timeStep);
	}

	void Game::PreRender()
	{
		renderer->RenderPrimitive(PrimitiveType::TRIANGLES);
	}

	void Game::EngineRender()
	{
		PreRender();
		if (!canLoadNewScene)
		{
			if (currentScene)
			{
				currentScene->Render();
			}
			RenderGame();
		}
		PostRender();
	}

	void Game::PostRender()
	{
		SDL_GL_SwapWindow(gameWindow->GetSDLWindow());
		glFlush();
	}
}