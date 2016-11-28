#include "stdafx.h"
#include "shaderProgramme.h"

shaderProgramme::shaderProgramme(std::string vertexFile,std::string fragmentFile)
{
	vertexShader = shaderFromFile(ResourcePath(vertexFile.c_str()), GL_VERTEX_SHADER);
	fragmentShader = shaderFromFile(ResourcePath(fragmentFile.c_str()), GL_FRAGMENT_SHADER);

}
void shaderProgramme::init(void) {
	programID = glCreateProgram();
	glAttachShader(programID, vertexShader);
	glAttachShader(programID, fragmentShader);
	BindAttributes();
	glLinkProgram(programID);
	glValidateProgram(programID);
	getAlluniformLocations();

}



const char * shaderProgramme::ResourcePath(const char *FilePath) {

	std::fstream hFile;

	//search for file by going up file directory tree up to 5 times
	int attempts = 0;
	nfilepath = "Resource/";
	nfilepath = nfilepath + FilePath;
	hFile.open(nfilepath.c_str(), std::ios::in);
	while (!hFile.is_open() && attempts < 5) {
		nfilepath = "../" + nfilepath;
		attempts += 1;
		hFile.open(nfilepath.c_str(), std::ios::in);
	}

	hFile.close();

	return nfilepath.c_str();
}

int shaderProgramme::shaderFromFile(const std::string filePath, GLenum shaderType) {
	//open file
	std::cout << "FILE NAME IS : " << filePath << std::endl;
	std::ifstream f;
	f.open(filePath.c_str(),std::ios::in);
	if (!f.is_open()) {
	throw std::runtime_error(std::string("Failed to open file: ") + filePath);
	}


	//read whole file into stringstream buffer
	std::stringstream buffer;
	buffer << f.rdbuf();
	buffer << "\0";
	f.close();

	std::string shaderCode = buffer.str().c_str(); // need to copy, as pointer is deleted when call is finished

												   //create new shader
	int ShaderID = glCreateShader(shaderType);

	//set the source code

	const GLchar * code = (const GLchar *)shaderCode.c_str();
	std::cout << code << std::endl;

	glShaderSource(ShaderID, 1,&code, NULL);
	//compile
	glCompileShader(ShaderID);


	//throw exception if compile error occurred
	GLint status;
	glGetShaderiv(ShaderID, GL_COMPILE_STATUS, &status);
	std::cout << "Status from compile:" << status << "\r\n";
	if (status == GL_FALSE) {
		std::string msg("Compile failure in shader:\n");

		GLint infoLogLength;
		glGetShaderiv(ShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
		char* strInfoLog = new char[infoLogLength + 1];
		glGetShaderInfoLog(ShaderID, infoLogLength, NULL, strInfoLog);
		msg += strInfoLog;
		delete[] strInfoLog;

		glDeleteShader(ShaderID); ShaderID = 0;
		std::cout << msg << std::endl;
		throw std::runtime_error(msg);
	}

	return ShaderID;
}
void shaderProgramme::bindAttribute(GLuint attribute,std::string variableName) {
	glBindAttribLocation(programID,attribute,variableName.c_str());
}

shaderProgramme::~shaderProgramme()
{
	stop();
	glDetachShader(programID, vertexShader);
	glDetachShader(programID, fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glDeleteProgram(programID);
}
