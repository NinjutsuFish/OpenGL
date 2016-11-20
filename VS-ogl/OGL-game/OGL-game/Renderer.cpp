#include "stdafx.h"
#include "Renderer.h"


Renderer::Renderer()
{
}
void Renderer::render(RawModel model) {
	glBindVertexArray(model.getvaoid());
	glEnableVertexAttribArray(0);
	glDrawElements(GL_TRIANGLES, model.getvertexCount(), GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}

Renderer::~Renderer()
{
}
