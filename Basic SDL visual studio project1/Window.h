#pragma once
#include <SDL.h>
#include <stdio.h>

class Window
{
public:
	static const int delKey = 0x4C; 
	Window(const char* name, int x, int y, int w, int h, uint32_t flags);
	~Window();
	bool quit;
	SDL_Event e;
	SDL_Window *wind; 
	SDL_Rect WindowRect; 
	SDL_Surface* windBrush; //change this to a Brush when the time is rihgt 
};



Window::Window(const char* name, int x, int y, int w, int h,  uint32_t flags =0 ) {
		wind = SDL_CreateWindow(name, x, y, w, h, flags);
		windBrush = SDL_GetWindowSurface(this->wind); 
		WindowRect = { x,y,w,h };
}


Window::~Window()
{
	SDL_free(this->wind); 
	SDL_free(this->windBrush);//once you change this to a Brush this will need to be removed
}