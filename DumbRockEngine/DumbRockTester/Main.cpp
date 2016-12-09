#include <LogManager.h>

#include "TestGame.h"
#include "GameTest.h"

GameTest gt;

void reshape(int w, int h)
{
	gt.Reshape(w, h);
}

void display()
{
	gt.Display();
}

void idle()
{
	gt.Idle();
}

void keyboard(unsigned char key, int x, int y)
{
	gt.Keyboard(key, x, y);
}

void mouse(int button, int state, int x, int y)
{
	gt.Mouse(button, state, x, y);
}

int main(int argc, char* argv[])
{
	LogManager::Initialize();

	//gt = GameTest();

	//gt.Initialize(argc, argv);

	TestGame* testGame = new TestGame();
	testGame->RunGame();

	delete testGame;
	testGame = nullptr;

	//glewInit();

	//glutKeyboardFunc(keyboard);
	//glutMouseFunc(mouse);
	//glutIdleFunc(idle);
	
	//glutReshapeFunc(reshape);
	//glutDisplayFunc(display);

	//glutMainLoop();

	return 0;
}