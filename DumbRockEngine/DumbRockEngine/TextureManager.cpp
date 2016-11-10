#include "TextureManager.h"

namespace DRE
{
	TextureManager* TextureManager::m_pInstance = nullptr;

	TextureManager* TextureManager::GetInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new TextureManager();
		}
		return m_pInstance;
	}

	TextureManager::TextureManager()
	{
		m_TextureList = new ResourceManager<Texture>();
	}

	TextureManager::~TextureManager()
	{

	}
}
