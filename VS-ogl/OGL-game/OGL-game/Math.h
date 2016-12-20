

#ifndef MATH_H_
#define MATH_H_

#define M_PI	3.145192

#include "glm/vec3.hpp" // glm::mat4
#include "glm/mat4x4.hpp" // glm::mat4
#include "glm/gtc/matrix_transform.hpp"// glm::translate, glm::rotate, glm::scale, glm::perspective
#include "Camera.h"

namespace Math {
	glm::mat4 CreateTransformationMatrix(const glm::vec3 translation, float rx,float fy, float rz,float scale);
	glm::mat4 create_transformation_matrix(const glm::vec2& translation,const glm::vec2& scale);
	float barrycentric(const glm::vec3& p1, const glm::vec3& p2,const glm::vec3& p3, const glm::vec2& pos);
	float toRadians(float angdeg);
	glm::mat4 createViewMatrix(Camera camera);
};

#endif /* MATH_H_ */
