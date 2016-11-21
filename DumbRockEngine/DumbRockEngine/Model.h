#ifndef _MODEL_H
#define _MODEL_H

#pragma once

#include <vector>
//#include <assimp/Importer.h>
//#include <assimp/scene.h>
//#include <assimp/postprocess.h>

#include "Mesh.h"
#include "DRE_typedef.h"

namespace DRE
{
	class Model
	{
	private:
		std::vector<Mesh> meshes;
		std::string directory;

		void LoadModel(std::string path) {

		}

		void ProcessNode() 
		{

		}

		Mesh ProcessMesh() 
		{

		}

		std::vector<Texture> LoadMaterialTextures()
		{

		}

	public:
		Model(GLchar* path)
		{
			this->LoadModel(path);
		}
	};
}

#endif
