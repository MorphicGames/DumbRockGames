#ifndef _TESTSCENE_H
#define _TESTSCENE_H

#pragma once

#include "Scene.h"

namespace DRE
{
	class TestScene : public Scene
	{
	public:
		TestScene();
		~TestScene();

		void InitializeScene();
		void Update(const F32 timeStep);
		void Render();
	};
}

#endif