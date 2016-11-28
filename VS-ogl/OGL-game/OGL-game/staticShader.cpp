#include "stdafx.h"
#include "staticShader.h"


void staticShader::BindAttributes() {
	bindAttribute(0, "position");
	bindAttribute(1, "textureCoords");
	
}
void staticShader::getAlluniformLocations() {
	loc_transformationMatrix = getUniformLocation("transformationMatrix");
	
	
}

staticShader::~staticShader()
{
}
