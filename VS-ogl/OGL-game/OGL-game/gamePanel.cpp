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
			// load support for the JPG and PNG image formats
			int flags = IMG_INIT_JPG | IMG_INIT_PNG;
			int initted = IMG_Init(flags);
			if ((initted&flags) != flags) {
				printf("IMG_Init: Failed to init required jpg and png support!\n");
				printf("IMG_Init: %s\n", IMG_GetError());
				// handle error
			}
			//adddeptj
			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LESS);
			//Update the surface
			SDL_UpdateWindowSurface(window);
			
			raw = myobj.loadObjModel("dragon.obj", load);
			texture = modelTexture(load.loadTexture("Green.png"));
			texture.setReflectivity(100);
			texture.setShineDamper(20);
			texmodel = texturedModel(raw, texture);
			
			//shader last!!! but not entirely after go therender and entities.... <- this was a not made after i had wrote shader Last!
			myshader = new staticShader();

			render = Renderer(myshader);
			
			myEntity = Entity(texmodel, glm::vec3(0, 0, -25), 0, 0, 0, 1);
		
				
			
			
			
			
			mylight = Light(glm::vec3(0,0,-20),glm::vec3(1,1,1));
		}
	}

}
//creation of render and update game....
void gamePanel::updateGame() {
	
		myEntity.IncreaseRotation(0, 0.3, 0);
	
	//camera.rotateCamera(glm::vec3(0, 1, 0));
}
void gamePanel::renderGame() {
	//DRAW MODELSSSSSSS
	
		render.prepare();
		myshader->start();
		myshader->loadLight(mylight);
		myshader->loadShineVariales(texture.getShineDamper(), texture.getReflectivity());
		render.render(myEntity, myshader, camera);

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
