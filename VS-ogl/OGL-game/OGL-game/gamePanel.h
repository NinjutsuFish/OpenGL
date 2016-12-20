#pragma once
#ifndef _included_gamePanel
#define _included_gamePanel

#include <stdlib.h>
#include <SDL.h>
#include "GL/glew.h"
#include "Loader.h"
#include"staticShader.h"
#include "RawModel.h"
#include "Renderer.h"
#include "modelTexture.h"
#include "texturedModel.h"
#include "Entity.h"
#include "objLoader.h"
#include "glm\vec3.hpp"
#include "Camera.h"
#include <vector>
#include "Light.h"
#define ScreenWidth	640
#define ScreenHeight	480
class gamePanel


{
public:
	gamePanel();
	~gamePanel();
private:
	modelTexture texture;
	texturedModel texmodel;
	int bob;
	//set screen width and height const === cannot be changed...
	
	//the winow handle
	SDL_Window* window;
	//surface within window for drawing...
	SDL_Surface* screenSurface;
	//exit
	bool quit = false;
	//event handler
	SDL_Event sdlEvent;
	//ogl context (Link between ogl and window)
	SDL_GLContext gContext;
	
	//function setting
	void init();
	void MainLoop();
	void updateGame();
	void renderGame();

	//loading etc
	Loader load;
	Renderer render;
	RawModel raw;
	staticShader * myshader;
	Entity myEntity;
	Camera camera;
	objLoader myobj;
	Light mylight;


};

#endif // _included_gamePanel