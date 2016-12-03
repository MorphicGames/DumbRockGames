#ifndef _MODEL_H
#define _MODEL_H

#pragma once

#include <vector>

#include "Mesh.h"
#include "DRE_typedef.h"
#include "LogManager.h"

struct aiNode;
struct aiMesh;
struct aiScene;
struct aiMaterial;
enum aiTextureType;

namespace DRE
{
	class Model
	{
	private:
		std::vector<Mesh> meshes;
		std::string directory;

		void LoadModel(std::string path);
		void ProcessNode(aiNode* node, const aiScene* scene);
		Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
		std::vector<Texture> LoadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
		GLint TextureFromFile(const char* path, std::string directory);

	public:
		Model(GLchar* path);

		void Render(ShaderProgram program);
	};
}

#endif
