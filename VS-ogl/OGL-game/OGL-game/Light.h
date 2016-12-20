#pragma once
#include "glm\vec3.hpp"


class Light
{
public:
	Light() {};
	Light(glm::vec3& Pos,glm::vec3& Color) {
		Colour = Color;
		Position = Pos;
	};
	~Light() {};
	//setters
	void setColour(glm::vec3 colour) { Colour = colour; }
	void setPosition(glm::vec3 pos) { Position = pos; }
	
	//getters
	glm::vec3 GetColour() { return Colour; }
	glm::vec3 GetPosition() { return Position; }
	
private:
	glm::vec3 Position;
	glm::vec3 Colour;

};

