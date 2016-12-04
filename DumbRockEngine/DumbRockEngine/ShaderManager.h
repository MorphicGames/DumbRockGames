#ifndef _SHADERMANAGER_H
#define _SHADERMANAGER_H

#pragma once

#include "ResourceManager.h"

#include "Shader.h"

#define SHADER_MANAGER DRE::ShaderManager::Instance()

namespace DRE
{
	class ShaderManager
	{
	private:
		ShaderManager();

		ResourceManager<Shader>* m_ShaderList;
	public:
		static ShaderManager& Instance();

		void AddShader(const std::string& shaderName, Shader* shader);
		Shader* GetShader(const std::string& shaderName);
	};
}

#endif