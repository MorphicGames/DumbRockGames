#pragma once
#ifndef INPUTMANAGER_H_DEFIND
#define INPUTMANAGER_H_DEFIND

#include "SDL.h"

class InputManager
{
public:
	static InputManager* getInstance();

	//THIS WILL UPDATE THE ENTIRE GAME INPUT STATE.
	//THIS SHOULD BE CALLED AT EVERY FRAME  TO ASSURE EXPECTED BEHAVAIOUR.
	//THIS WILL PRIMARY BE RESPONSIBLE FOR CHECKING THE KEYBOARD AND MOUSE CALLS.
	void update(float cameraX = 0, float cameraY = 0);

	//TELLS IF KEY IS DOWN
	bool isKeyDown(int key);

	//TELLS IF KEY IS UP
	bool isKeyUp(int Key);

	//TELLS IF THE MOUSE BUTTON IS DOWN
	bool isMouseDown(uint8_t button);

	//TELLS IF THE MOUSE BUTTON IS UP
	bool isMouseUp(uint8_t button);

	//TELLS IF THE "KEY" IS CURRENTLY BEING PRESSED
	bool isKeyPressed(int Key);

	//TELLS IF THE MOUSE "BUTTON" IS CURRENTLY BEING PRESSED
	bool isMousePressed(uint8_t button);

	//TELLS IF THE USE ASKED THE GAME TABLE TO QUIT
	bool quitRequested();

	//RETURNS THE CURRENT MOUSE X POSITION
	int getMouseX();

	//RETURNS THE CURRENT MOUSE Y POSITION
	int getMouseY();
	
	//LOCKS THE "INPUTMANAGER", PREVENTING IT TO ACTUALLY REFRESH INPUT AND MAKING ALL METHODS RETURN "FALSE"
	void lock();
	
	//UNLOCKS THE "INPUTMANAGER", ALLOWING IT TO RESPOND NORMALLY TO INPUT
	void unlock();

	//TELLS IF THE MOUSE IS CURRENTLY INSIDE THE RECTANGLE
	//SPECIFIED BY #X, #Y, #W, #H
	bool isMouseInside(int x, int y, int w, int h);

	//TELLS IF THE "KEY" CAN BE PRINTED ONSCREEN (NOT A CONTROL KEY)
	//IF A KEY IS VISIBLE ACCORDING TO THE ASCII TABLE
	static bool isPrintable(SDL_Keycode key);
	bool isPrintableKeyDown();
	std::string getCurPrinableKey();
	
	//WUT
	InputManager();

	//REMOVING COPY-CONSTRUCTOR AND ASSGINEMT OPERATOR
	InputManager(InputManager const&) {};
	void operator=(InputManager const&) {};

private:

	//CURRENT SINGLE INSTANCE OF THE CLASS
	static InputManager* instance;

	//SAVE SDL INTERNAL MOUSE STATE
	uint8_t mouse;

	//CURRENT MOUSE X POSITION
	int mouseX;

	//CURRENT MOUSE Y POSITION
	int mouseY;

	//SAVE WHICH KEYS ARE CURRENTLY DOWN
	bool keyDown[KEYBOARD_SIZE];

	//SAVE WHICH KEYS ARE CURRENTLY UP
	bool keyUp[KEYBOARD_SIZE];

	//SAVE WHICH MOUSE BUTTONS ARE CURRENTLY DOWN
	bool mouseDown[MOUSE_SIZE];

	//SAVE WHICH MOUSE BUTTONS ARE CURRENTLY UP
	bool mouseUp[MOUSE_SIZE];

	//TELLS IF WE MUST QUIT THE GAME
	bool will_quit;

	//IF THE USER PRESSED THE A PRINTABLE KEY, THIS IS WHERE IT WILL BE STORED
	int curPrintableKey;

	//TELLS IF THE MANAGER IS CURRENTLY LOCKED
	bool isLocked;

};
#endif 
