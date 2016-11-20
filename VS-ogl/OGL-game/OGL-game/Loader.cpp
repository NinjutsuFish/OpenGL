#include "stdafx.h"
#include "Loader.h"
#

Loader::Loader()
{
}
RawModel Loader::LoadToVAO(const float*postions, const long numpoints,const GLuint * indices, const long numIndices ){
	int vaoID = createVao();
	bindIndicesBuffer(indices, numIndices);
	StoreDataInAttribbuteList(0, postions, numpoints);
	UnbindVao();
	return RawModel(vaoID, numIndices);


}

GLuint Loader::createVao() {
	GLuint vaoID[2];
	glGenVertexArrays(1, (GLuint *)&vaoID);
	glBindVertexArray(vaoID[0]);
	vaoList.push_back(vaoID[0]);
	
	return vaoID[0];
}

void Loader::UnbindVao() {
	glBindVertexArray(0);
}
void Loader::StoreDataInAttribbuteList(int attributenumber, const float*data, const long numpoints) {
	GLuint vboID[1];
	glGenBuffers(1, (GLuint *)&vboID);
	glBindBuffer(GL_ARRAY_BUFFER,vboID[0]);
	glBufferData(GL_ARRAY_BUFFER,numpoints*sizeof(float), storeDataInBuffer(data, numpoints), GL_STATIC_DRAW);
	glVertexAttribPointer(attributenumber, 3, GL_FLOAT, false, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	vboList.push_back(vboID[0]);
	

}
void *  Loader::storeDataInBuffer(const float *positions, const long numPoints) {

	floatbuffer.clear();
	for (int count = 0; count<numPoints; count++) {
		floatbuffer.push_back(positions[count]);
	}
	return floatbuffer.data();
}
void Loader::bindIndicesBuffer(const GLuint *indices, const long numpointer) {
	GLuint vboID[1];
	glGenBuffers(1, (GLuint *)&vboID);
	vboList.push_back(vboID[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID[0]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,numpointer*sizeof(GLuint),StoredatainIntBuffer(indices, numpointer),GL_STATIC_DRAW);
}



void * Loader::StoredatainIntBuffer(const GLuint *inices, const long numpointer) {
	indexBuffer.clear();
		for (int count = 0; count<numpointer; count++) {
			indexBuffer.push_back(inices[count]);
		}

	return indexBuffer.data();
}
Loader::~Loader()
{
	glDeleteVertexArrays(vaoList.size(), vaoList.data());
	glDeleteBuffers(vboList.size(), vboList.data());




}
