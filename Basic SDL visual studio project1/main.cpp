#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Functions.h"

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
		Player player; 
		World world; 
		auto eh = Window("default test Window", SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
		defaultEventLoop(&eh, &player, &world); 
	}
	//SDL_Quit(); //this is not nessisary in C++ because the implicit destructors are called
	//and what ever is not trivaly descructable is cleaned up by the kernal
	//for somereason this is causing the program to hang on quit so do not use SDL_Quit
	return 0;
}