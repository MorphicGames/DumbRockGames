#ifndef _TESTSCENE_H
#define _TESTSCENE_H

#pragma once

#include "Scene.h"

using namespace DRE;

class TestScene : public DRE::Scene
{
public:
	TestScene();
	~TestScene();

	void InitializeScene();
	void Update(const F32 timeStep);
	void Render();
};

#endif