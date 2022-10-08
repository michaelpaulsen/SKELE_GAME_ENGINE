#pragma once
#include <stdint.h>
class Color
{
protected:
	uint32_t color;
public:
	static const uint32_t RED_MASK = 0xff0000;
	static const uint32_t GREEN_MASK = 0x00ff00;
	static const uint32_t BLUE_MASK = 0x0000ff;
	
	Color(uint32_t color);
	Color(uint8_t r, uint8_t g, uint8_t b);
	Color();
	~Color();

	uint8_t GetRedComp();
	void SetRedComp(uint8_t);
	
	uint8_t GetBlueComp();
	void SetBlueComp(uint8_t);
	
	uint8_t GetGreenComp();
	void SetGreenComp(uint8_t);
	
	uint32_t GetAllComp();
	void SetAllComp(uint32_t);

};



Color::Color(uint32_t _color): color(_color) {};
Color::Color(): color(0) {};
Color::Color(uint8_t r, uint8_t g, uint8_t b)
{
	this->color = r << (32-8); 
	this->color |= g << (32-16); 
	this->color |= b; 
}



Color::~Color() = default;
uint8_t  Color::GetRedComp() {
	return static_cast<uint8_t>((this->color &  RED_MASK) >> (32 - 8));
};
void  Color::SetRedComp(uint8_t) {};
uint8_t  Color::GetBlueComp() {
	return static_cast<uint8_t>((this->color &  BLUE_MASK) >> (32 - 16));
};
void  Color::SetBlueComp(uint8_t) {
};
uint8_t  Color::GetGreenComp() {
	return static_cast<uint8_t>((this->color &  GREEN_MASK));
};
void  Color::SetGreenComp(uint8_t) {};
uint32_t Color::GetAllComp() {
	return this->color; 
};
void  Color::SetAllComp(uint32_t newColor) {
	this->color = newColor;
};