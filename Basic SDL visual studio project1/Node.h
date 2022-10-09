#pragma once
#include <SDL.h> 

class GameObject{
protected: 
	int  x, y;
	GameObject() = default;
	GameObject(int  _x, int  _y) : x(_x), y(_y) {};
public: 
	
	int  GetX() {
		return this->x; 
	}
	void SetX(int  _x) {
		this->x = _x; 
	}
	void IncX() {
		this->x++; 
	}
	void DecX() {
		this->x--; 
	}
	void IncX(int  f) {
		this->x+=f; 
	}
	void DecX(int  f) {
		this->x-=f; 
	}
	int  GetY() {
		return this->y; 
	}
	void SetY(int  _y) {
		this->y = _y; 
	}
	void IncY() {
		this->y++; 
	}
	void DecY() {
		this->y--;
	}
	void IncY(int  f) {
		this->y+=f; 
	}
	void DecY(int  f) {
		this->y-=f;
	}
	
	void operator--() {
		this->x--;
		this->y--;
	}
	void operator++() {
		this->x++;
		this->y++;
	}
	void operator+= (int  o) {
		this->x += o; 
		this->y += o;
	}
	void operator+= (GameObject o) {
		this->x += o.GetX(); 
		this->y += o.GetY();
	}
	virtual SDL_Rect toSLD_Rect() {
		return { x,y,0,0 }; 
	}
};