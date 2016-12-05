#include <LogManager.h>

#include "TestGame.h"

int main(int argc, char* argv[])
{
	LogManager::Initialize();

	TestGame* testGame = new TestGame();
	testGame->RunGame();

	delete testGame;
	testGame = nullptr;

	return 0;
}