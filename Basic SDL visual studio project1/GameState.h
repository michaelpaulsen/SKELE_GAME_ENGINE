#pragma once
#include <SDL.h>
#include<stdint.h>

struct GameState_t {
	bool quit = false, isKeyDown = false, isMouseKeyDown = false, isScreenValid = false, isMouseMove = false, isMouseScroll = false, isTextEditEvent = false;
	int lastKeyDown;
	char LastTextEditEventValue[32] = { 0 };
	int8_t LastMouseKeyDown; 
	int32_t LastMouseX, LastMouseY; 
	SDL_Surface surface; 
	//SDL_Event* e;
	void resetState() { ///resets the screen 
		//quit = false;
		isKeyDown = false;
		isMouseKeyDown = false;
		isMouseMove = false;
		isMouseScroll = false;
		isTextEditEvent = false;
		isScreenValid = true;
	}
	auto PrintState() {
		return printf("Game Quit state %d\n", quit);
	}
};