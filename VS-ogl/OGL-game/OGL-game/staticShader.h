#pragma once
#include "shaderProgramme.h"
#define	vertex_FileName	"vertexShader.txt"
#define	fragment_FileName	"fragmentShader.txt"

class staticShader :
	public shaderProgramme
{
public:
	staticShader() :shaderProgramme(vertex_FileName, fragment_FileName) { init(); }

	~staticShader(); 
	void BindAttributes();
};

