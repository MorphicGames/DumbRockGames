#ifndef _TIMER_H
#define _TIMER_H

#pragma once

#include "DRE_typedef.h"

namespace DRE
{
	class Timer
	{
	private:
		unsigned int prevTicks;
		unsigned int currTicks;
	public:
		Timer();
		~Timer();

		void Start();
		void UpdateFrameTicks();
		float GetDeltaTime() const;
		unsigned int GetSleepTime(const U32 _fps) const;
	};
}

#endif