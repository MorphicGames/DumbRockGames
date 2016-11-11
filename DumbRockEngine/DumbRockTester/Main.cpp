#include "TesterGame.h"

using namespace DRE;

static TesterGame* tg;

int main(int argc, char* argv[])
{
	tg = new TesterGame();

	tg->StartGame();

	P_DELETE(tg);

	return 0;
}