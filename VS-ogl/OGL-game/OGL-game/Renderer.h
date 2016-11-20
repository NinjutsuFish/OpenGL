#pragma once
#include <GL\glew.h>
#include "RawModel.h"
class Renderer
{
public:
	Renderer();
	~Renderer();
	void prepare() {
		glClearColor(0.f, 255.f, 100.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void render(RawModel model);
private:
};

