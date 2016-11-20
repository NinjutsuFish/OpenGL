#pragma once
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>
#include <iostream>



#include <GL\glew.h>

class shaderProgramme
{
public:
	shaderProgramme(std::string vertexFile, std::string fragmentFile);
	~shaderProgramme();
	virtual void BindAttributes() = 0;
	void init(void);
	void bindAttribute(GLuint attribute, std::string variableName);
	void start(void) { glUseProgram(programID); }
	void stop(void) { glUseProgram(0); }
private:
	GLuint programID;
	GLuint vertexShader;
	GLuint fragmentShader;
	std::string nfilepath;
	const char * ResourcePath(const char *FilePath);
	int shaderFromFile(const std::string filePath, GLenum shaderType);

	

};

