#include "TesterGame.h"

using namespace DRE;

int main(int argc, char* argv[])
{
	TesterGame* tg = new TesterGame();

	tg->StartGame();

	delete tg;
	tg = nullptr;

	return 0;
}