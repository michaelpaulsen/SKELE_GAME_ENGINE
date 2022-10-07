#pragma once
#include <SDL.h>
#include <functional>
#include <vector>

class Player
{
	
public:
	int x, y; 
	Player();
	Player(int x, int y);
	~Player();
};



Player::Player(){
	x = 0; 
	y = 0;
}
Player::Player(int x, int y){
}


Player::~Player()
{
}
