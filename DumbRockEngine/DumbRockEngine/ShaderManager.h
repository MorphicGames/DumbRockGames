#ifndef _SHADERMANAGER_H
#define _SHADERMANAGER_H

#pragma once

#include "ResourceManager.h"

#include "Shader.h"

namespace DRE
{
	class ShaderManager
	{
	private:
		ShaderManager();
		~ShaderManager();

		ResourceManager<Shader>* m_ShaderList;

		static ShaderManager* m_pInstance;

	public:
		static ShaderManager* GetInstance();
	};
}

#endif