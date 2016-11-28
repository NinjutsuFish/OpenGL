
#include "stdafx.h"
#include "Math.h"

namespace Math {

	float toRadians(float angdeg) {
		return angdeg / 180.0 * M_PI;
	}

	glm::mat4 CreateTransformationMatrix(const glm::vec3 translation, float rx, float ry, float rz, float scale) {


		glm::mat4 matrix = glm::mat4(1.0f);
		matrix = glm::translate(matrix, translation);
		if (rx != 0)  matrix = glm::rotate(matrix, toRadians(rx), glm::vec3(1, 0, 0));
		if (ry != 0)  matrix = glm::rotate(matrix, toRadians(ry), glm::vec3(0, 1, 0));
		if (rz != 0)  matrix = glm::rotate(matrix, toRadians(rz), glm::vec3(0, 0, 1));
		matrix = glm::scale(matrix, glm::vec3(scale, scale, scale));

		return matrix;
	}


	float barrycentric(const glm::vec3& p1, const glm::vec3& p2,
		const glm::vec3& p3, const glm::vec2& pos)
	{
		float det = (p2.z - p3.z) * (p1.x - p3.x) + (p3.x - p2.x) * (p1.z - p3.z);
		float l1 = ((p2.z - p3.z) * (pos.x - p3.x) + (p3.x - p2.x) * (pos.y - p3.z)) / det;
		float l2 = ((p3.z - p1.z) * (pos.x - p3.x) + (p1.x - p3.x) * (pos.y - p3.z)) / det;
		float l3 = 1.0f - l1 - l2;
		return l1 * p1.y + l2 * p2.y + l3 * p3.y;
	}

	glm::mat4 create_transformation_matrix(const glm::vec2& translation,
		const glm::vec2& scale)
	{
		glm::mat4 matrix{};
		matrix = glm::translate(matrix, glm::vec3{ translation, 0.0f });
		matrix = glm::scale(matrix, glm::vec3{ scale, 1.0f });
		return matrix;
	}

}

