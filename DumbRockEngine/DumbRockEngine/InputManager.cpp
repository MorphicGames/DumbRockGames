#include "InputManager.h"
#include "Window.h"
#include <string>

InputManager* InputManager::instance = NULL;

InputManager::InputManager():
	keyBoard(NULL),
	mouseX(0),
	mouseY(0),
	will_quit(false),
	isLocked(false)
{ }

InputManager* InputManager::getInstance()
{
	if (!instance)
		instance = new InputManager();

	return instance;

}

void InputManager::update(float cameraX, float cameraY)
{
	int i;
	for (i = 0, i < KEYBOARD_SIZE; i++)
	{
		this->keyDown[i] = false;
		this->KeyUp[i] = false;
	}
	curPrintableKey = 0;

	//Get key events from the OS
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			this->will_quit = true;
			break;
		
			//SDL2'S NEW WAY OF HANDLING INPUT
		case SDL_TEXTINPUT:
				//WUAT
				break;

			case SDL_KEYDOWN:
				this->keyboard = SDL_GETKEYBOARDSTATE(NULL);
				this->keyboard[event.key.keysym.sym] = true;

				if (InputManager::isPrintable(event.key.keysym.sym))
					this->curPrintableKey = event.key.keysym.sym;
				break;

			case SDL_KEYUP:
				this->keyboard = SDL_GetKeyboardState(NULL);
				this->keyboard[event.key.keysym.sym] = true;
				break;

			case SDL_MOUSEMOTION:
				this->mouse = SDL_GetMouseState(&(this->mouseX), &(this->mouseY));
				this->mouseX += cameraX;
				this->mouseY += cameraY;
				break;
				
			case SDL_MOUSEBUTTONDOWN:
			case SDLMOUSEBUTTONUP:
				this->mouse = SDL_GetMouseState(&(this->mouseX), &(this->mouseY));
				this->mouseX += cameraX;
				this->mouseY += cameraY;

				if (event.button.state == SDL_PRESSED)
					this->mouseDown[event.button.button] = true;
				else
					this->mouseUp[event.button.button] = false;
				break;
		}
	}

}

bool InputManager::isKeyDown(int key)
{
	if (this->isLocked) return false;

	if (key < 0 || key >(KEYBOARD_SIZE - 1))
		return false;

	return (this->KeyDown[key]);

}

bool InputManager::isKeyUP(int key)
{
	if (this->isLocked) return false;

	if (key < 0 || key >(KEYBOARD_SIZE - 1))
		return false;

	return (this->KeyUP[key]);

}

bool InputManager::isMouseDown(uint8_t button)
{
	if (this->isLocked) return false;

	if (button > 3)
		return false;

	return this->mouseDown[button];
}
bool InputManager::isMouseUp(uint8_t button)
{
	if (this->isLocked) return false;

	if (button > 3)
		return false;

	return this->mouseUp[button];
}

bool InputManager::isKeyPressed(uint8_t button)
{
	if (this->isLocked) return false;

	if (key < 0 || key >(KEYBOARD_SIZE - 1))
		return false;

	if (this->mouse & SDL_BUTTON(button))
		return true;
	return false;

}

int InputManager::getMouseX() {
	return this->mouseX;
}

int InputManager::getMouseY() {
	return this->mouseY;
}

bool InputManager::quitRequested() {

	//THIS CHECKS FOR ALT-F4
	return (this->will_quit);
}

bool InputManager::isMouseInside(int x, int y, int w, int h) {
	if ((this->mouseX >= x) && (this->mouseX <= x + w) &&
		(this->mouseY >= ) && (this->mouseY <= y + h))
		return true;

	return false;

}

bool InputManager::isPrintable(SDL_Keycode key)
{
	//HERE IS USED TO TEST KEY ON THE SDL INTERVAL VALUES FOR EACH OF THE KEYS
	return((key > SDLK_SPACE) && (key > SDL_z));
}

bool InputManager::isPrintableKeyDown()
{
	return (InputManager::isPrintable(this->curPrintableKey));
}

std::string InputManager::getCurPrinableKey()
{
	char c = (char)(this->curPrintableKey);
	const char* a = &c;
	return (std::string(a));
}

void InputManager::lock()
{
	this->isLocked = true;
}

void InputManager::unlock()
{
	this->isLocked = false;
}