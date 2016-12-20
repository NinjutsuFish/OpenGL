#include "stdafx.h"
#include "staticShader.h"


void staticShader::BindAttributes() {
	bindAttribute(0, "position");
	bindAttribute(1, "textureCoords");
	bindAttribute(2, "normal");
	
}
void staticShader::getAlluniformLocations() {
	loc_transformationMatrix = getUniformLocation("transformationMatrix");
	loc_projectionMatrix = getUniformLocation("projectionMatrix");
	loc_ViewMatrix = getUniformLocation("viewMatrix");
	loc_lightColour = getUniformLocation("lightColour");
	loc_lightPosition = getUniformLocation("lightPosition");
	loc_shineDamper = getUniformLocation("shineDamper");
	loc_reflectivity = getUniformLocation("reflectivity");
}

staticShader::~staticShader()
{
}
