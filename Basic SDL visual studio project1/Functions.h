#pragma once
#include <SDL.h>
#include <stdint.h> 

#include "GameState.h"
#include "Enity.h"
#include "Player.h"
#include "World.h"
#include "Color.h"

bool defaultEventLoop(Window* window, Player* p, World *current) {
	bool quit = false;
	size_t bgc_index = 0;
	auto screenSurface = SDL_GetWindowSurface(window->wind);
	Color backgroundColors[4] = { Color(0xafafaf),Color(0xaf0000),Color(0x00af00),Color(0x0000af) };
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
					quit = (modstate[1] && keysym.scancode == Window::delKey); //ctrl + del close the window
					switch (keysym.sym) {
					case 'w': {
						printf("w pressed\n");

						bgc_index = 0;
						break;
					}
					case 'd': {
						printf("d pressed\n");
						bgc_index = 1;
						break;
					}
					case 's': {
						printf("s pressed\n");

						bgc_index = 2;
						break;

					}
					case 'a': {
						printf("a pressed\n");

						bgc_index = 3;
						break;

					}
					}
				}
				printf("filling screen with %06x\n", backgroundColors[bgc_index].GetAllComp());
				break;
			}
			case SDL_KEYUP: {
				break;
			}
			case SDL_WINDOWEVENT: {
				printf("window state changed\n");
				SDL_GetWindowSize(window->wind, &window->WindowRect.w, &window->WindowRect.h);
				SDL_GetWindowPosition(window->wind, &window->WindowRect.x, &window->WindowRect.y); //this may be unneeded but no reason not to. 
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
		SDL_FillRect(screenSurface, &screenSurface->clip_rect, backgroundColors[bgc_index].GetAllComp());
		SDL_UpdateWindowSurface(window->wind);
	}
	return true;
}