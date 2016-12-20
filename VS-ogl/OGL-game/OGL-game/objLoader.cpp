#include "stdafx.h"
#include "OBJloader.h"


RawModel objLoader::loadObjModel(std::string objfilename, Loader& Loader)
{

	std::ifstream file{ ResourcePath(objfilename) };
	//file.exceptions(std::ios::failbit);


	std::string line;

	while (!file.eof()) {

		std::getline(file, line);
		if (line.empty()) {
			continue;
		}

		std::vector<std::string> current_line = split(line, 32);

		if (startsWith(line, "v ")) {

			vertices.push_back(glm::vec3(std::stof(current_line.at(1)),
				std::stof(current_line.at(2)),
				std::stof(current_line.at(3))));
		}
		else if (startsWith(line, "vt")) {
			textures.push_back(glm::vec2(std::stof(current_line.at(1)),
				std::stof(current_line.at(2))));
		}
		else if (startsWith(line, "vn")) {
			normals.push_back(glm::vec3(std::stof(current_line.at(1)),
				std::stof(current_line.at(2)),
				std::stof(current_line.at(3))));
		}
		else if (startsWith(line, "f ")) {
			texture_array.resize(vertices.size() * 2);
			normals_array.resize(vertices.size() * 3);
			break;
		}
	}

	while (!line.empty()) {
		if (!startsWith(line, "f ")) {
			std::getline(file, line);
			continue;
		}

		std::vector<std::string> current_line = split(line, 32);
		std::vector<std::string>  vertex1 = split(current_line.at(1), 47);
		std::vector<std::string>  vertex2 = split(current_line.at(2), 47);
		std::vector<std::string>  vertex3 = split(current_line.at(3), 47);

		auto process_vertex = [&](const std::vector<std::string> & vertex_data) {
			int current_vertex_pointer = std::stoi(vertex_data.at(0)) - 1;
			indices.push_back(current_vertex_pointer);

			glm::vec2 current_tex = textures.at(std::stoi(vertex_data.at(1)) - 1);
			texture_array.at(current_vertex_pointer * 2) = current_tex.x;
			texture_array.at(current_vertex_pointer * 2 + 1) = current_tex.y;

			glm::vec3 current_norm = normals.at(std::stoi(vertex_data.at(2)) - 1);
			normals_array.at(current_vertex_pointer * 3) = current_norm.x;
			normals_array.at(current_vertex_pointer * 3 + 1) = current_norm.y;
			normals_array.at(current_vertex_pointer * 3 + 2) = current_norm.z;
		};

		process_vertex(vertex1);
		process_vertex(vertex2);
		process_vertex(vertex3);

		std::getline(file, line);
	}
	file.close();
	// Will this function never end...

	vertices_array.reserve(vertices.size() * 3);

	for (const auto& vertex : vertices) {
		vertices_array.push_back(vertex.x);
		vertices_array.push_back(vertex.y);
		vertices_array.push_back(vertex.z);
	}
	return Loader.LoadToVAO2(vertices_array, indices, texture_array, normals_array);

}

	objLoader::objLoader() {
}


	objLoader::~objLoader()
{
}
