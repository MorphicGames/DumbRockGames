#include <LogManager.h>

#include "TestGame.h"

int main(int argc, char* argv[])
{
	LogManager::Initialize();

	TestGame testGame;
	testGame.RunGame();

	return 0;
}