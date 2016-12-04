#ifndef _TEXTUREMANAGER_H
#define _TEXTUREMANAGER_H

#pragma once

#include "ResourceManager.h"

#define TEXTURE_MANAGER DRE::TextureManager::Instance()

class Texture;

namespace DRE
{
	class TextureManager
	{
	private:
		TextureManager();
		ResourceManager<Texture>* m_TextureList;
	public:
		static TextureManager& Instance();
	};
}

#endif