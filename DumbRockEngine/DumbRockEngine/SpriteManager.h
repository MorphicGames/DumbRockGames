#ifndef _SPRITEMANAGER_H
#define _SPRITEMANAGER_H

#pragma once

#include "ResourceManager.h"

class Sprite;

namespace DRE
{
	class SpriteManager
	{
	private:
		SpriteManager();
		~SpriteManager();

		ResourceManager<Sprite>* m_SpriteList;

		static SpriteManager* m_pInstance;

	public:
		static SpriteManager* GetInstance();
	};
}

#endif