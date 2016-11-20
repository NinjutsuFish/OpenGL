#pragma once

#include <stdlib.h>
#include <SDL.h>
#include "GL/glew.h"
#include "Loader.h"
#include"staticShader.h"
#include "RawModel.h"
#include "Renderer.h"
class gamePanel


{
public:
	gamePanel();
	~gamePanel();
private:
	int bob;
	//set screen width and height const === cannot be changed...
	const int ScreenWidth=640;
	const int ScreenHeight=480;
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


};

