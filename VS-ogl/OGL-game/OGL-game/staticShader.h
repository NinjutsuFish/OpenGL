#pragma once
#include "shaderProgramme.h"
#include "Camera.h"
#include "Math.h"
#include "Light.h"
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
	void loadViewMatrix(Camera camera) { glm::mat4 matrix = Math::createViewMatrix(camera); LoadMatrix(loc_ViewMatrix, matrix); }
	void loadLight(Light light) { loadVector(loc_lightPosition, light.GetPosition()); loadVector(loc_lightColour, light.GetColour()); }
	void loadShineVariales(float Damper, float reflectiveness) { loadFloat(loc_shineDamper, Damper); loadFloat(loc_reflectivity, reflectiveness); }

private:
	GLuint loc_transformationMatrix;
	GLuint loc_projectionMatrix;
	GLuint loc_ViewMatrix;
	GLuint loc_lightColour;
	GLuint loc_lightPosition;
	GLuint loc_shineDamper;
	GLuint loc_reflectivity;
};

