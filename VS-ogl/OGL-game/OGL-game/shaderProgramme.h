#pragma once
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>
#include <iostream>
#include "glm\vec3.hpp"
#include "glm\gtc\type_ptr.hpp"


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
	//uniform Stufffff
	GLuint getUniformLocation(std::string UniformName) { return glGetUniformLocation(programID, UniformName.c_str()); };
	virtual void getAlluniformLocations() = 0;
	//uniform setters
	void loadFloat(GLuint Location, float Value) { glUniform1f(Location, Value); }
	void loadVector(GLuint Location, glm::vec3 value) { glUniform3f(Location, value.x,value.y,value.z); };
	void LoadBoolean(GLuint Location, bool value) { GLfloat ValueToLoad = 0; if (value) { ValueToLoad = 1.0; }glUniform1f(Location,ValueToLoad); }
	void LoadMatrix(GLuint Location, glm::mat4 matrix) { glUniformMatrix4fv(Location, 1, false, glm::value_ptr(matrix)); }
private:
	GLuint programID;
	GLuint vertexShader;
	GLuint fragmentShader;
	std::string nfilepath;
	const char * ResourcePath(const char *FilePath);
	int shaderFromFile(const std::string filePath, GLenum shaderType);

	

};

