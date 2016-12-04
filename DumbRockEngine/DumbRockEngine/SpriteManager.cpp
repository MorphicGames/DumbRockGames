#include "SpriteManager.h"

namespace DRE
{
	SpriteManager& SpriteManager::Instance()
	{
		static SpriteManager *instance = new SpriteManager();
		return *instance;
	}

	SpriteManager::SpriteManager()
	{
		m_SpriteList = new ResourceManager<Sprite>();
	}
}
