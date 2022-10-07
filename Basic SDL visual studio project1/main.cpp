#include <SDL.h>
#include <stdio.h>
#include "Window.h"

//Screen dimension constants
constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;
constexpr int tileSize = 16; 
int main(int argc, char* args[]){
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else {
		auto eh = Window("default test Window", SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	}
	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}