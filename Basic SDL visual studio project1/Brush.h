#pragma once
#include <SDL.h>
#include <stdint.h>
class Brush {
	SDL_Renderer* renderer; 
	SDL_Surface* windowSurface; 
public: 

	explicit Brush(SDL_Window* window) {
		this->renderer = SDL_CreateRenderer(window, -1, 0);
		this->windowSurface = SDL_GetWindowSurface(window);
	}
	Brush(SDL_Window* window, uint32_t flags) { 
		this->windowSurface = SDL_GetWindowSurface(window);
		this->renderer = SDL_CreateRenderer(window, -1, flags);
	}
	void DrawPoint(int x, int y) {
		SDL_RenderDrawPoint(this->renderer, x, y);
	}
	void SetColor(uint8_t r, uint8_t  g, uint8_t b) {
		SDL_SetRenderDrawColor(this->renderer,r, g, b,0xff);
	} 
	void SetColor(uint8_t r, uint8_t  g, uint8_t b, uint8_t a) {
		SDL_SetRenderDrawColor(this->renderer,r, g, b,a);
	} 
	//SDL_RenderPresent(brush.get)
	void RenderPresent() {
		SDL_RenderPresent(this->renderer);
	}
	void R_FillRect(SDL_Rect *dim) {
		SDL_RenderFillRect(this->renderer, dim);
	}
		
};