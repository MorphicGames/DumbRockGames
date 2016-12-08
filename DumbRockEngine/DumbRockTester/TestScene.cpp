#include "TestScene.h"

using namespace DRE;

TestScene::TestScene()
	//: DRE::Scene()
{
	SetSceneName("Title Screen");
}

TestScene::~TestScene()
{

}

void TestScene::InitializeScene()
{
	std::cout << "break";
}

void TestScene::Update(const F32 timeStep)
{
	Scene::Update(timeStep);
}

void TestScene::Render()
{

}
