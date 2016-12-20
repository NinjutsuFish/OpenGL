#pragma once
#include "GL/glew.h"
#include <SDL.h>
#include <GL\GL.h>
#include <SDL_image.h>
#include <vector>
class modelTexture
{
public:
	modelTexture(GLuint texturenum) { textureID = texturenum;
	shineDamper = 1.0f;
	reflectivity = 10.0f;
	}
	~modelTexture() {};
	GLuint getID() { return textureID; }
	modelTexture() {};
	//setters for shine
	void setShineDamper(float value) { shineDamper = value; }
	void setReflectivity(float value) { reflectivity = value; }
	//getters
	float getShineDamper() { return shineDamper; }
	float getReflectivity() { return reflectivity; }

private:
	GLuint textureID;
	float shineDamper ;
	float reflectivity ;
};

