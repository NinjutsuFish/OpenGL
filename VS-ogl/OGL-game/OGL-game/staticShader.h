#pragma once
#include "shaderProgramme.h"
#define	vertex_FileName	"vertexShader.txt"
#define	fragment_FileName	"fragmentShader.txt"

class staticShader :
	public shaderProgramme
{
public:
	staticShader() :shaderProgramme(vertex_FileName, fragment_FileName) { init(); }
	//uniform mat4 transformationMatrix important <<<|||>>>>
	~staticShader(); 
	void BindAttributes();
	void getAlluniformLocations();
	void loadTransformationMatrix(glm::mat4 matrix) { LoadMatrix(loc_transformationMatrix, matrix); }
	void loadprojectionMatrix(glm::mat4 matrix) { LoadMatrix(loc_projectionMatrix, matrix); }
private:
	GLuint loc_transformationMatrix;
	GLuint loc_projectionMatrix;
};

