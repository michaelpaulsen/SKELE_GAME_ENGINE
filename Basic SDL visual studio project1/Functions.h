#pragma once
#include <SDL.h>
#include <stdint.h> 

#include "GameState.h"
#include "Enity.h"
#include "Player.h"
#include "World.h"
#include "Color.h"

bool defaultEventLoop(Window* window, Player* p, World *current) {
	uint64_t ticks = 0; 
	bool quit = false;
	size_t bgc_index = 0;
	auto screenSurface = SDL_GetWindowSurface(window->wind);
	Color backgroundColors[4] = { Color(0x000000),Color(0xaf0000),Color(0x00af00),Color(0x0000af) };
	SDL_Rect bounds; 
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
				break;
			}
			case SDL_MOUSEBUTTONDOWN: {
				break;
			}
			case SDL_MOUSEBUTTONUP: {
				break;
			}
			case SDL_KEYDOWN: {
				auto kevent = e.key;
				auto keysym = kevent.keysym;
				if (!kevent.repeat) {
					auto state = SDL_GetModState();
					int modstate[3] = { state & KMOD_ALT,  state & KMOD_CTRL, state & KMOD_GUI };
					quit = (modstate[1] && keysym.scancode == Window::delKey); //ctrl + del close the window
					
					}
				switch (keysym.sym) {
				case 'w': {
					p->IncY(-2);
					bgc_index = 0;
					break;
				}
				case 'd': {
					p->IncX(2);
					bgc_index = 1;
					break;
				}
				case 's': {
					p->IncY(2);

					bgc_index = 2;
					break;

				}
				case 'a': {
					p->IncX(-2);
					bgc_index = 3;
					break;

				}
				}
				printf("player pos (%d,%d) World w&h (%d,%d) \n", p->GetX(),p->GetY(), screenSurface->clip_rect.w, screenSurface->clip_rect.h);
				break;
			}
			case SDL_KEYUP: {
				break;
			}
			case SDL_WINDOWEVENT: {
				screenSurface = SDL_GetWindowSurface(window->wind); 
				break;
			}
			case SDL_TEXTEDITING: {
				break;
			}
			case SDL_TEXTINPUT: {
				break;
			}
			default: {
				printf("unhandeled event: %d (%X)\n", e.type, e.type);
				break;
			}
			}
		}
		bounds = { p->GetW(), p->GetH(), screenSurface->clip_rect.w - (p->GetW()*2), screenSurface->clip_rect.h - (p->GetH() * 2) };
		if(p->GetX() < 0){
			p->SetX(screenSurface->clip_rect.w-p->GetW());
		}
		if(p->GetX() > screenSurface->clip_rect.w - p->GetW() ){
			p->SetX(0);
		}
		if(p->GetY() < 0){
			p->SetY(screenSurface->clip_rect.h - p->GetH());
		}
		if(p->GetY() > screenSurface->clip_rect.h - p->GetH() ){
			p->SetY(0);
		}

		
		SDL_FillRect(screenSurface, &screenSurface->clip_rect,0xffffff);
		SDL_FillRect(screenSurface, &bounds, 0xaaaaaa);
		SDL_FillRect(screenSurface, &p->toSLD_Rect(), backgroundColors[bgc_index].GetAllComp());
		SDL_UpdateWindowSurface(window->wind);
		ticks++; 
	}
	return true;
}