#include "TestGame.h"

#include "TestScene.h"

TestGame::TestGame()
{
	
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

}

void TestGame::RenderGame()
{

}
