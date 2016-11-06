#ifndef _DRE_GAME_H
#define _DRE_GAME_H

#pragma once

namespace DRE
{
	class DRE_Game
	{
		friend class Engine;

	public:
		DRE_Game() {
			//Nothing in here to see, stop stalling and work 0^0
		}
		virtual ~DRE_Game() = 0;

	protected:
		virtual bool Initialize()	= 0;
		virtual bool Update()		= 0;
		virtual bool Render()		= 0;
		virtual void Shutdown()		= 0;
	};
}

#endif