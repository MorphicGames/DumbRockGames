#include "Window.h"
#include "DRE_defines.h"
#include "LogManager.h"

#include <glew.h>

namespace DRE
{
	Window::Window(const char* windowTitle)
	{
		this->m_WindowTitle = windowTitle;
		this->m_pWindowRect = new SDL_Rect();
	}

	Window::~Window()
	{
		Shutdown();
	}

	bool Window::Initialize()
	{
		LogManager::LogMessage(LogMessageType::INFO, "Initializing Window...", __FILE__, __LINE__);

		m_bIsInitialized = false;

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			LogManager::LogMessage(LogMessageType::FATAL_ERROR, "Failed to Initialize SDL_VIDEO!", __FILE__, __LINE__);
			return m_bIsInitialized;
		}

		m_pSDLWindow = SDL_CreateWindow(m_WindowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_pWindowRect->w, m_pWindowRect->h, SDL_WINDOW_OPENGL);
		if (!m_pSDLWindow)
		{
			Shutdown();
			LogManager::LogMessage(LogMessageType::FATAL_ERROR, "Failed to Create Window!", __FILE__, __LINE__);
			return m_bIsInitialized;
		}

		m_SDLContext = SDL_GL_CreateContext(m_pSDLWindow);

		SetOpenGLAttributes();

		SDL_GL_SetSwapInterval(1);

#ifndef __APPLE__
		glewExperimental = GL_TRUE;
		glewInit();
#endif

		m_bIsInitialized = true;

		return m_bIsInitialized;
	}

	void Window::Shutdown()
	{
		LogManager::LogMessage(LogMessageType::INFO, "Shutting Down Window...", __FILE__, __LINE__);

		SDL_GL_DeleteContext(m_SDLContext);

		SDL_DestroyWindow(m_pSDLWindow);

		P_DELETE(m_pWindowRect);
	}

	void Window::ToggleFullscreen()
	{
		m_bIsFullscreen = !m_bIsFullscreen;
		SDL_SetWindowFullscreen(m_pSDLWindow, (m_bIsFullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN));
	}

	void Window::SetWindowSize(const int width, const int height)
	{
		m_pWindowRect->w = width;
		m_pWindowRect->h = height;
	}

	int Window::GetWindowWidth() const
	{
		return m_pWindowRect->w;
	}

	int Window::GetWindowHeight() const
	{
		return m_pWindowRect->h;
	}

	SDL_Window* Window::GetSDLWindow() const
	{
		return m_pSDLWindow;
	}

	void Window::SetOpenGLAttributes()
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	}
}
