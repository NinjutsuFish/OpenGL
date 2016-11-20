#pragma once
#include "RawModel.h"
#include "GL/glew.h"
#include <vector>

class Loader
{
public:
	Loader();
	~Loader();
	void StoreDataInAttribbuteList(int attributenumber, const float*data,const long numpoints);
	RawModel LoadToVAO(const float*postions, const long numpoints, const GLuint * indices, const long numIndices);
private:
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
	
};

