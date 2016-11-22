#pragma once
#include "GL/glew.h"
#include <SDL.h>
#include <GL\GL.h>
#include <SDL_image.h>
#include <vector>
class modelTexture
{
public:
	modelTexture(GLuint texturenum);
	~modelTexture();
	GLuint getID() { return textureID; }

private:
	GLuint textureID;
};

