#include "SpriteManager.h"

namespace DRE
{
	SpriteManager* SpriteManager::m_pInstance = nullptr;

	SpriteManager* SpriteManager::GetInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new SpriteManager();
		}
		return m_pInstance;
	}

	SpriteManager::SpriteManager()
	{
		m_SpriteList = new ResourceManager<Sprite>();
	}

	SpriteManager::~SpriteManager()
	{

	}
}
