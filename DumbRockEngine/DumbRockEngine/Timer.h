#ifndef _TIMER_H
#define _TIMER_H

#pragma once

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
		unsigned int GetSleepTime(const unsigned int _fps) const;
	};
}

#endif