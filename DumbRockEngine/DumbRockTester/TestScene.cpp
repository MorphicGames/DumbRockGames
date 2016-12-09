#include "TestScene.h"

using namespace DRE;

TestScene::TestScene()
	: DRE::Scene()
{
	SetSceneName("Title Screen");
}

TestScene::~TestScene()
{

}

void TestScene::InitializeScene()
{
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<Texture> textures;

	Vertex v;
	v.position = glm::vec3(-0.5f, 0.0f, 0.5f);
	v.normal = glm::vec3(0.0f);
	v.textureCoords = glm::vec2(1.0f, 0.0f);
	vertices.push_back(v);

	v.position = glm::vec3(-0.5f, 0.0f, -0.5f);
	v.normal = glm::vec3(0.0f);
	v.textureCoords = glm::vec2(1.0f, 0.0f);
	vertices.push_back(v);

	v.position = glm::vec3(0.5f, 0.0f, -0.5f);
	v.normal = glm::vec3(0.0f);
	v.textureCoords = glm::vec2(1.0f, 1.0f);
	vertices.push_back(v);

	v.position = glm::vec3(0.5f, 0.0f, 0.5f);
	v.normal = glm::vec3(0.0f);
	v.textureCoords = glm::vec2(1.0f, 1.0f);
	vertices.push_back(v);

	v.position = glm::vec3(-0.5f, 1.0f, 0.5f);
	v.normal = glm::vec3(0.0f);
	v.textureCoords = glm::vec2(0.0f, 1.0f);
	vertices.push_back(v);

	v.position = glm::vec3(0.5f, 1.0f, 0.5f);
	v.normal = glm::vec3(0.0f);
	v.textureCoords = glm::vec2(0.0f, 1.0f);
	vertices.push_back(v);

	v.position = glm::vec3(0.5f, 1.0f, -0.5f);
	v.normal = glm::vec3(0.0f);
	v.textureCoords = glm::vec2(0.0f, 0.0f);
	vertices.push_back(v);

	v.position = glm::vec3(-0.5f, 1.0f, -0.5f);
	v.normal = glm::vec3(0.0f);
	v.textureCoords = glm::vec2(0.0f, 0.0f);
	vertices.push_back(v);

	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(3);

	indices.push_back(3);
	indices.push_back(4);
	indices.push_back(1);

	indices.push_back(5);
	indices.push_back(6);
	indices.push_back(7);

	indices.push_back(7);
	indices.push_back(8);
	indices.push_back(5);

	indices.push_back(1);
	indices.push_back(4);
	indices.push_back(6);

	indices.push_back(6);
	indices.push_back(5);
	indices.push_back(1);

	indices.push_back(4);
	indices.push_back(3);
	indices.push_back(7);

	indices.push_back(7);
	indices.push_back(6);
	indices.push_back(4);

	indices.push_back(3);
	indices.push_back(2);
	indices.push_back(8);

	indices.push_back(8);
	indices.push_back(7);
	indices.push_back(3);

	indices.push_back(2);
	indices.push_back(1);
	indices.push_back(5);

	indices.push_back(5);
	indices.push_back(8);
	indices.push_back(2);

	testMesh = new Mesh(vertices, indices, textures);

	Shader vertex = Shader("TestVertexShader", ShaderType::VERTEX);
	Shader fragment = Shader("TestFragmentShader", ShaderType::FRAGMENT);

	program.AttachShader(vertex);
	program.AttachShader(fragment);

	program.UseProgram();
}

void TestScene::Update(const F32 timeStep)
{
	Scene::Update(timeStep);
}

void TestScene::Render()
{
	//LogManager::LogMessage(LogMessageType::INFO, "Rendering", __FILE__, __LINE__);
	//testMesh->SimpleRender();
	//testMesh->Render(program);


}
