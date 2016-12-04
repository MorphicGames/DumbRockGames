#ifndef _INPUTMANAGER_H
#define _INPUTMANAGER_H

#include "SDL\include\SDL.h"
#include <map>
#include "OpenGL\glm\glm\glm.hpp"

#include "DRE_typedef.h"

#define INPUT_MANAGER DRE::InputManager::Instance()

namespace DRE
{
	class InputManager
	{
	private:
		InputManager();

	public:
		static InputManager& Instance();

		SDL_MouseMotionEvent motionEvent;

		void Update();
		void ProcessInput(SDL_Event& SDLEvent);

		void PressKey(SDL_Keycode keyID);
		void ReleaseKey(SDL_Keycode keyID);

		void HitMouse(Uint8 key);
		void ReleaseMouse(Uint8 key);
		void SetMouseCoord(const F32 x, const F32 y);

		bool IsKeyDown(SDL_Keycode key);
		bool IsKeyPressed(SDL_Keycode key);
		bool IsKeyReleased(SDL_Keycode key);
		bool IsAnyKeyDown();

		bool IsMouseButtonDown(Uint8 button);
		bool IsMouseButtonPressed(Uint8 button);
		bool IsMouseButtonReleased(Uint8 button);

	protected:
		glm::vec2 oldMousePosition;
		glm::vec2 currentMousePosition;

		std::map<SDL_Keycode, bool> currentKeyboardMap;
		std::map<SDL_Keycode, bool> oldKeyboardMap;

		std::map<Uint8, bool> currentMouseMap;
		std::map<Uint8, bool> oldMouseMap;
	};
}

#endif 
