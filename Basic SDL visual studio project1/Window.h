#pragma once
#include <SDL.h>
#include <stdio.h>
#include <functional>
#include <vector>


#include "GameState.h"
#include "Enity.h"
#include "Player.h"
#include "World.h"

#define SKCGE_EVENT_HANDLE_T std::function<bool (Player*, World)> 
class Window
{
public:
	static const int delKey = 0x4C; 
	Window(const char* name, int x, int y, int w, int h, SKCGE_EVENT_HANDLE_T eventLoop, uint32_t flags);
	~Window();
	SKCGE_EVENT_HANDLE_T EventLoop; 
	bool quit;
	SDL_Event e;
	SDL_Window *wind; 
	static bool defaultEventLoop(Player* p, World current);
};



Window::Window(const char* name, int x, int y, int w, int h, SKCGE_EVENT_HANDLE_T eventLoop = Window::defaultEventLoop,  uint32_t flags =0 ) {
		wind = SDL_CreateWindow(name, x, y, w, h, flags);
		EventLoop = eventLoop;
}


Window::~Window()
{
	SDL_free(this->wind); 

}
bool Window::defaultEventLoop(Player* p, World current) {
	bool quit = false;
	SDL_Event e; 
	while (!quit) {
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_QUIT: {
				quit = true;
				break;
			}
			case SDL_MOUSEMOTION: {
				auto mevent = e.motion;
				//int worldx, worldy;
				break;
			}
			case SDL_MOUSEBUTTONDOWN: {
				auto btn = e.button;
				printf("mouse %d pressed button %d", btn.which, btn.button);
				break;
			}
			case SDL_MOUSEBUTTONUP: {
				auto btn = e.button;
				printf("mouse %d pressed button %d", btn.which, btn.button);
				break;
			}
			case SDL_KEYDOWN: {
				auto kevent = e.key;
				auto keysym = kevent.keysym;
				if (!kevent.repeat) {
					auto state = SDL_GetModState();
					int modstate[3] = { state & KMOD_ALT,  state & KMOD_CTRL, state & KMOD_GUI };
					printf("user pressed ");
					if (modstate[0]) {
						printf("ALT + ");
					}
					if (modstate[1]) {
						printf("CTRL + ");
					}
					if (modstate[2]) {
						printf("GUI + ");
					}
					printf(" %c (scancode: %X) \n", keysym.sym, keysym.scancode);
					quit = (modstate[1]  && keysym.scancode == Window::delKey); //ctrl + w close the window 
				}
				break;

			}
			case SDL_KEYUP: {
				break;
			}
			case SDL_WINDOWEVENT: {
				printf("window state changed\n");
				break;
			}
			case SDL_TEXTEDITING: {
				printf("editing text %s", e.text.text);
				//printf("a \"SDL_TEXTEDITING\" event happend \n");
				break;
			}
			case SDL_TEXTINPUT: {
				auto text = e.text;
				printf("a \"SDL_TEXTINPUT\" event happend \n\ttext inputed (%s)\n", text.text);
				break;
			}
			default: {
				printf("unhandeled event: %d (%X)\n", e.type, e.type);
				break;
			}
			}
		}
	}
	return true;
}