#include "Timer.h"

#include <SDL.h>

namespace DRE
{
	Timer::Timer() :prevTicks(0), currTicks(0)
	{
	}


	Timer::~Timer()
	{
	}

	void Timer::Start()
	{
		prevTicks = SDL_GetTicks();
		currTicks = SDL_GetTicks();
	}

	void Timer::UpdateFrameTicks()
	{
		prevTicks = currTicks;
		currTicks = SDL_GetTicks();
	}

	float Timer::GetDeltaTime() const
	{
		return (currTicks - prevTicks) / 1000.0f;
	}

	unsigned int Timer::GetSleepTime(const unsigned int _fps) const
	{
		unsigned int _milliSecsPerFrame = 1000 / _fps;
		if (_milliSecsPerFrame == 0)
		{
			return 0;
		}

		unsigned int sleepTime = _milliSecsPerFrame - (SDL_GetTicks());
		if (sleepTime > _milliSecsPerFrame)
		{
			return _milliSecsPerFrame;
		}
		return sleepTime;
	}
}
