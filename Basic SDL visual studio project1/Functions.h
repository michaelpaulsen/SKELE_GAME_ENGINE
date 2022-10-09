#pragma once
#include <SDL.h>
#include <stdint.h>
#include <cstring>

#include "GameState.h"
#include "Enity.h"
#include "Player.h"
#include "World.h"
#include "Color.h"
#include "GameState.h"
void PopulateGameState(SDL_Event e, GameState_t& GameState) {
	GameState.resetState(); 
	switch (e.type)
		{
		case SDL_QUIT: {
			//printf("quit Event ");
			GameState.quit = true; 
			break;
		}
		case SDL_MOUSEMOTION: {
			
			GameState.isMouseMove = true; //set the isMouse moved event; 
			GameState.LastMouseX = e.motion.x;
			GameState.LastMouseY = e.motion.y;
			break;
		}
		case SDL_MOUSEBUTTONDOWN: {
			GameState.isMouseKeyDown = true;
			GameState.LastMouseX = e.button.x;
			GameState.LastMouseY = e.button.y;
			break;
		}
		case SDL_MOUSEWHEEL: {
			GameState.isMouseScroll = 1; 
			GameState.LastMouseX = e.wheel.x;
			GameState.LastMouseY = e.wheel.y;
			break;
		}
		case SDL_MOUSEBUTTONUP: {
			//this may not be needed bc the GameState is reset for each event
			break;
		}
		
		case SDL_KEYDOWN: {
			printf("key pressed (%c)\n", e.key.keysym.sym);
			GameState.isKeyDown = true; 
			GameState.lastKeyDown = e.key.keysym.sym;
			
			break;
		}
		case SDL_KEYUP: {
			break;
		}
		case SDL_WINDOWEVENT: {
			break;
		}
		case SDL_TEXTEDITING: {
			GameState.isTextEditEvent = 1; 
			memmove(GameState.LastTextEditEventValue, e.edit.text, 32);
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