#ifndef _ENGINE_H
#define _ENGINE_H

#pragma once

#include "Window.h"
#include "OpenGLRenderer.h"

namespace DRE
{
	class GameEngine
	{
	public:
		GameEngine()
			: m_pAbstractRenderer(nullptr)
			, isRunning(false) 
		{
			//Needs Implementation
		}
		virtual ~GameEngine() 
		{
			//Needs Implementation
		}

		virtual void StartGame()	= 0;

		bool IsRunning() { return isRunning; }

	protected:
		virtual void OnStart()		= 0;
		virtual void OnEnd()		= 0;

		virtual void Update()		= 0;
		virtual void LateUpdate()	= 0;

		virtual void PreRender()	= 0;
		virtual void Render()		= 0;
		virtual void PostRender()	= 0;

		bool isRunning;

		U32 targetFPS;

		Window* m_pWindow;
		AbstractRenderer* m_pAbstractRenderer;
	};
}

#endif