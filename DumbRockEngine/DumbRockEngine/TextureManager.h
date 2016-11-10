#ifndef _TEXTUREMANAGER_H
#define _TEXTUREMANAGER_H

#pragma once

#include "ResourceManager.h"

class Texture;

namespace DRE
{
	class TextureManager
	{
	private:
		TextureManager();
		~TextureManager();

		ResourceManager<Texture>* m_TextureList;

		static TextureManager* m_pInstance;

	public:
		static TextureManager* GetInstance();
	};
}

#endif