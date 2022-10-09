#pragma once
#include <SDL.h>
#include <functional>
#include <vector>
#include "Node.h"

class Player : public GameObject
{
	
public:
	Player() {
		this->y = 0;
		this->x = 0;
	};
	Player(float _x, float _y) {
		this->x = _x;
		this->y = _y;
	};
	~Player() = default; 
};