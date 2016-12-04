#ifndef _SPRITEMANAGER_H
#define _SPRITEMANAGER_H

#pragma once

#include "ResourceManager.h"

#define SPRITE_MANAGER DRE::SpriteManager::Instance()

class Sprite;

namespace DRE
{
	class SpriteManager
	{
	private:
		SpriteManager();
		ResourceManager<Sprite>* m_SpriteList;
	public:
		static SpriteManager& Instance();
	};
}

#endif