#include "TestGame.h"

#include "TestScene.h"

TestGame::TestGame()
{
	//FIX
	instance = this;
}

TestGame::~TestGame()
{

}

bool TestGame::InitializeGame()
{
	LoadScene(new TestScene());

	return true;
}

void TestGame::UpdateGame(const F32 deltaTime)
{
	LogManager::ConsoleMessage("Updating Game");
}

void TestGame::RenderGame()
{
	LogManager::ConsoleMessage("Rendering Game");
}
