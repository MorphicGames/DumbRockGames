#include "InputManager.h"

namespace DRE
{
	InputManager::InputManager()
	{

	}

	InputManager& InputManager::Instance()
	{
		static InputManager *instance = new InputManager();
		return *instance;
	}

	void InputManager::Update()
	{
		oldMousePosition = currentMousePosition;
		oldKeyboardMap = currentKeyboardMap;
		oldMouseMap = currentMouseMap;

		I32 x, y;

		SDL_GetMouseState(&x, &y);
		SetMouseCoord(x, y);

		motionEvent = SDL_MouseMotionEvent();
	}

	void InputManager::ProcessInput(SDL_Event& SDLEvent)
	{
		switch (SDLEvent.type) 
		{
			case SDL_KEYDOWN:
				PressKey(SDLEvent.key.keysym.sym);
				break;
			case SDL_KEYUP:
				ReleaseKey(SDLEvent.key.keysym.sym);
				break;
			case SDL_MOUSEBUTTONDOWN:
				HitMouse(SDLEvent.button.button);
				break;
			case SDL_MOUSEBUTTONUP:
				ReleaseMouse(SDLEvent.button.button);
				break;
			case SDL_MOUSEMOTION:
				motionEvent = SDLEvent.motion;
				break;
		}
	}

	void InputManager::PressKey(SDL_Keycode keyID)
	{
		currentKeyboardMap[keyID] = true;
	}

	void InputManager::ReleaseKey(SDL_Keycode keyID)
	{
		currentKeyboardMap[keyID] = false;
	}

	void InputManager::HitMouse(Uint8 key)
	{
		currentMouseMap[key] = true;
	}

	void InputManager::ReleaseMouse(Uint8 key)
	{
		currentMouseMap[key] = false;
	}

	void InputManager::SetMouseCoord(const F32 x, const F32 y)
	{
		currentMousePosition = glm::vec2(x, y);
	}

	bool InputManager::IsKeyDown(SDL_Keycode key)
	{
		return (currentKeyboardMap[key]);
	}

	bool InputManager::IsKeyPressed(SDL_Keycode key)
	{
		return (!oldKeyboardMap[key] && currentKeyboardMap[key]);
	}

	bool InputManager::IsKeyReleased(SDL_Keycode key)
	{
		return (oldKeyboardMap[key] && !currentKeyboardMap[key]);
	}

	bool InputManager::IsAnyKeyDown()
	{
		for (auto iter = currentKeyboardMap.begin(); iter != currentKeyboardMap.end(); iter++)
		{
			if (iter->second == true)
				return true;
		}

		for (auto iter = currentKeyboardMap.begin(); iter != currentKeyboardMap.end(); iter++)
		{
			if (iter->second == true)
				return true;
		}

		return false;
	}

	bool InputManager::IsMouseButtonDown(Uint8 button)
	{
		return currentMouseMap[button];
	}

	bool InputManager::IsMouseButtonPressed(Uint8 button)
	{
		return (!oldMouseMap[button] && currentMouseMap[button]);
	}

	bool InputManager::IsMouseButtonReleased(Uint8 button)
	{
		return (oldMouseMap[button] && !currentMouseMap[button]);
	}
}