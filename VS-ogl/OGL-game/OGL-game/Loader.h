#pragma once
#include "RawModel.h"
#include "GL/glew.h"
#include <SDL.h>
#include <GL\GL.h>
#include <SDL_image.h>
#include <vector>
#include <iostream>
#include <fstream>

class Loader
{
public:
	Loader();
	~Loader();
	void StoreDataInAttribbuteList(int attributenumber, const float*data,const long numpoints,int numpointer);
	RawModel LoadToVAO(const float*postions, const long numpoints,
		const GLuint * indices, const long numIndices,
		const GLfloat *texcoords, const long numtexpoint);
	GLuint loadTexture(std::string fileName);
	RawModel LoadToVAO2(const std::vector<float>& Postition,
		const std::vector<GLuint>& indices,
		const std::vector<float>& texcoords,
		const std::vector<float>& normcoords);



private:
	
	std::string ResourcePath(std::string FilePath) {
		
		std::fstream hFile;
		std::string nfilepath = "Resource/";
		
		//search for file by going up file directory tree up to 5 times
		int attempts = 0;
		nfilepath = nfilepath + FilePath;
		hFile.open(nfilepath.c_str(), std::ios::in);
		while (!hFile.is_open() && attempts < 5) {
			nfilepath = "../" + nfilepath;
			attempts += 1;
			hFile.open(nfilepath.c_str(), std::ios::in);
		}

		hFile.close();

		return nfilepath;
	}
	GLuint createVao();
	void UnbindVao();
	void * storeDataInBuffer(const float *positions, const long numPoints);
	void bindIndicesBuffer(const GLuint *indices,const long numpointer);
	void * StoredatainIntBuffer(const GLuint *inices, const long numpointer);
	//buffer lists
	std::vector<GLfloat> floatbuffer;
	std::vector<GLuint> indexBuffer;
	std::vector<GLuint> vaoList;
	std::vector<GLuint> vboList;
	std::vector<GLuint> textureList;
	
};

