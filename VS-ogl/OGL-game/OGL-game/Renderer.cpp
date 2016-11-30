#include "stdafx.h"
#include"Renderer.h"



Renderer::Renderer(staticShader * shader)
{
	createProjectionMatrix();
	shader -> start();
	shader -> loadprojectionMatrix(projectionMatrix);
	shader -> stop();
}
void Renderer::render(Entity myEntity, staticShader * Shader) {
	texturedModel model = myEntity.getModel();
	RawModel modelraw = model.getModel();
	glBindVertexArray(modelraw.getvaoid());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glm::mat4 Matrix = Math::CreateTransformationMatrix(myEntity.getPos(),myEntity.getRotx(), myEntity.getRoty(), myEntity.getRotz(),myEntity.getScale());
	
	Shader->loadTransformationMatrix(Matrix);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, model.getTexture().getID());
	glDrawElements(GL_TRIANGLES, modelraw.getvertexCount(), GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
	
}
void Renderer::createProjectionMatrix(){
	projectionMatrix = glm::perspectiveFov((float)FOV,// FOV
		(float)ScreenWidth,
		(float)ScreenHeight,
		(float)NEAR_PLANE,
		(float)FAR_PLANE);
	
}

Renderer::~Renderer()
{
}
