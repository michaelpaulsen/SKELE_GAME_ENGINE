#pragma once
#include <functional>
#include <vector>
#include "Node.h"

class Player : public GameObject
{
protected:
	int w, h; 
public:
	Player(): w(0), h(0){
		y = 0;
		x = 0;
	};
	Player(int _x, int _y, int _w, int _h): w(_w), h(_h) {
		x = _x;
		y = _y;
		
	};
	int GetW() {
		return w; 
	}
	int GetH() {
		return h; 
	}
	~Player() = default; 
	SDL_Rect toSLD_Rect() override { 
		return { x,y,w,h }; 
	}
};