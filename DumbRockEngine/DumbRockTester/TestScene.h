#ifndef _TESTSCENE_H
#define _TESTSCENE_H

#pragma once

#include "Scene.h"

namespace DRE
{
	class TestScene : public Scene
	{
	protected:
		Mesh* testMesh;

		ShaderProgram program;

	public:
		TestScene();
		~TestScene();

		void InitializeScene();
		void Update(const F32 timeStep);
		void Render();
	};
}

#endif