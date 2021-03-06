#pragma once
#ifndef _included_renderer
#define _included_renderer

#include <GL\glew.h>
#include "Math.h"
#include "glm/mat4x4.hpp"
#include "Renderer.h"
#include "Entity.h"
#include "staticShader.h"
#include "texturedModel.h"
#include "RawModel.h"
#include "modelTexture.h"

#define ScreenWidth	640
#define ScreenHeight	480

#define FOV	70
#define NEAR_PLANE	0.1f
#define FAR_PLANE 1000

class Renderer
{
public:
	Renderer() { };
	Renderer(staticShader * shader);
	~Renderer();
	void prepare() {
		glClearColor(25.f, 0.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void render(Entity myEntity, staticShader * Shader,Camera camera);
private:
	glm::mat4 projectionMatrix;
	void createProjectionMatrix();
	modelTexture ModelT;
	
};

#endif // _included_renderer