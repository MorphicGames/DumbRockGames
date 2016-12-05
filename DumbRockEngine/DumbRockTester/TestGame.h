#ifndef _TESTGAME_H
#define _TESTGAME_H

#pragma once

#include "Game.h"

using namespace DRE;

class TestGame : public Game
{
public:
	TestGame();
	~TestGame();

	bool InitializeGame() override;

	void UpdateGame(const F32 deltaTime) override;
	void RenderGame() override;
};

#endif