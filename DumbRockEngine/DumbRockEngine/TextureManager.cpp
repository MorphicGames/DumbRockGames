#include "TextureManager.h"

namespace DRE
{
	TextureManager& TextureManager::Instance()
	{
		static TextureManager *instance = new TextureManager();
		return *instance;
	}

	TextureManager::TextureManager()
	{
		m_TextureList = new ResourceManager<Texture>();
	}
}
