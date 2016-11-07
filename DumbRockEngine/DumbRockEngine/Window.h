#ifndef _WINDOW_H
#define _WINDOW_H

#pragma once

#include "DRE_typedef.h"

#include "SDL/include/SDL.h"

namespace DRE
{
	class Window
	{
		friend class Engine;

	public:
		Window(const char* windowTitle);
		~Window();

		bool Initialize();
		void Shutdown();

		void ToggleFullscreen();	
		void SetWindowSize(const int width, const int height);

		int GetWindowWidth() const;
		int GetWindowHeight() const;

	private:
		bool m_bIsFullscreen;
		bool m_bIsInitialized;

		void SetOpenGLAttributes();

		const char* m_WindowTitle;

		SDL_Window* m_pSDLWindow;
		SDL_GLContext m_SDLContext;

		SDL_Rect m_WindowRect;
	};
}

#endif