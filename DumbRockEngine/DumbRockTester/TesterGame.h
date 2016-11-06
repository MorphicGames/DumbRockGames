#ifndef TESTERGAME_H
#define TESTERGAME_H

#pragma once

#include "GameEngine.h"

namespace DRE
{
	class TesterGame : public GameEngine
	{
	public:
		TesterGame();
		~TesterGame();

		virtual void StartGame();

	protected:
		virtual void OnStart();
		virtual void OnEnd();

		virtual void Update();
		virtual void LateUpdate();

		virtual void PreRender();
		virtual void Render();
		virtual void PostRender();
	};
}

#endif