#pragma once
#include "RawModel.h"
#include <vector>
#include "glm/vec3.hpp"
#include "glm/vec2.hpp"

#include <fstream>
#include<string.h>
#include  <sstream>
#include "Loader.h"


using namespace std;
class objLoader
{
public:
	objLoader();
	~objLoader();
	RawModel loadObjModel(std::string filename, Loader& loader);
	string ResourcePath(std::string FilePath) {
		
		std::fstream hFile;
		string nfilepath = "Resource/";

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
	std::vector<std::string> split(std::string str, char delimiter) {
		std::vector<std::string> internal;
		std::stringstream ss(str); // Turn the string into a stream.
		std::string tok;

		while (getline(ss, tok, delimiter)) {
			internal.push_back(tok);
		}

		return internal;
	}

	bool startsWith(std::string input, std::string tofind) {
		// strncmp = exact match = 0, anything else mismatch
		return (strncmp(input.c_str(), tofind.c_str(), tofind.length()) == 0);
	}
private:

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> textures;
	std::vector<glm::vec3> normals;
	std::vector<GLuint> indices;

	std::vector<float> vertices_array;
	std::vector<float> texture_array;
	std::vector<float> normals_array;

};

