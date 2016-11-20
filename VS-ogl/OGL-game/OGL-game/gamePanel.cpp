#include "stdafx.h"
#include "gamePanel.h"
#include <string>
#include <iostream>
using namespace std;

gamePanel::gamePanel()
{
	cout << "Game Panel Constructor .... :)" << endl;;
	//set screen objectsto null
	window = NULL;
	screenSurface = NULL;
	//variable setters..
	gContext = NULL;

	//intialise library
	init();

	MainLoop();


}
//define init function 
void gamePanel::MainLoop() {
	while (!quit) {
		//event handle on queue
		while (SDL_PollEvent(&sdlEvent) != 0)
		{
			//User requests quit
			if (sdlEvent.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		updateGame();
		renderGame();
	}

	} 


void gamePanel::init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		//check if intialised
		cout << "SDL COULD NOT BE INTIALISED :(";
	}
	else//is initialised !!!! YAYYY:)
	{
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ScreenWidth, ScreenHeight,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			cout << "Window was NOT succesfully intialised";
		}
		else
		{
			//useopengl 4./3.2 cant rember which
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);


			//end of opengl stting thing
			cout << "Window is happy" << endl;;
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);
			//context creation :))))
			gContext = SDL_GL_CreateContext(window);
			if (gContext == NULL) {
				cout << "Context Creation FAILED :( not good" << endl;
			} else {
				//Use Vsync
				if (SDL_GL_SetSwapInterval(1) < 0)
				{
					std::cout << "Warning: Unable to set VSync! SDL Error:" << SDL_GetError() << std::endl;
				}

			}

			glewInit();

			if (!GLEW_ARB_vertex_array_object){
				std::cout << "ARB_vertex_array_object not available." << std::endl;
		}

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));

			//Update the surface
			SDL_UpdateWindowSurface(window);
			float vertices[] = { -0.5f, 0.5f, 0.0f,
								-0.5f, -0.5f, 0.0f,
								0.5f, -0.5f, 0.0f,
								0.5f, 0.5f, 0.0f};
			
			GLuint indices[] = { 0,1,3,3,1,2 };
			
			cout << raw.getvaoid() << "Hai" << endl;;
			

			
			raw = load.LoadToVAO((float *)&vertices, 12,(GLuint *)&indices,6);
			myshader = new staticShader();
		}
	}

}
//creation of render and update game....
void gamePanel::updateGame() {

}
void gamePanel::renderGame() {
	//DRAW MODELSSSSSSS
	render.prepare();
	myshader->start();
	render.render(raw);
	myshader->stop();




	//swap buffers
	SDL_GL_SwapWindow(window);
}


gamePanel::~gamePanel()
{
	cout << "The class was DESTROYED";
	//clean up
	if (window != NULL) {
		SDL_DestroyWindow(window);

	}
	SDL_Quit();
	





}
