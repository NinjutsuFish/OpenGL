#include "stdafx.h"
#include"Renderer.h"



Renderer::Renderer(staticShader * shader)
{
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	createProjectionMatrix();
	shader -> start();
	
	shader -> loadprojectionMatrix(projectionMatrix);
	shader -> stop();
}
void Renderer::render(Entity myEntity, staticShader * Shader,Camera camera) {
	texturedModel model = myEntity.getModel();
	RawModel modelraw = model.getModel();
	modelTexture bob = model.getTexture();
	glBindVertexArray(modelraw.getvaoid());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glm::mat4 Matrix = Math::CreateTransformationMatrix(myEntity.getPos(),myEntity.getRotx(), myEntity.getRoty(), myEntity.getRotz(),myEntity.getScale());
	
	Shader->loadTransformationMatrix(Matrix);
	Shader->loadShineVariales(bob.getShineDamper(), bob.getReflectivity());
	Shader->loadViewMatrix(camera);
	//std::cout << "Damper :" << ModelT.getShineDamper() << "  Reflecitivty:" << ModelT.getReflectivity() << std::endl;

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, model.getTexture().getID());
	
	glDrawElements(GL_TRIANGLES, modelraw.getvertexCount(), GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(2);
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
