#include "TesterGame.h"

using namespace DRE;

int main(int argc, char* argv[])
{
	TesterGame* tg = new TesterGame();

	tg->StartGame();

	P_DELETE(tg);

	return 0;
}