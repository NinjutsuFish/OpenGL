#include "stdafx.h"
#include "Camera.h"


Camera::Camera()
{
	position = glm::vec3(0.0, 0.0, 0.0);
	roll = 0.0;
	pitch = 0.0;
	yaw = 0.0;
}
void Camera::MoveCamera(glm::vec3 direction,float amount){
	if (direction.x) {
		position.x += amount;

	}
	if (direction.y) {
		position.y += amount;

	}
	if (direction.z) {
		position.z += amount;

	}


//std::cout << "X:" << direction.x << "\n Y:" << direction.y << "\n Z:" << direction.z;


}
void Camera::rotateCamera(glm::vec3 rotation) {
	roll += rotation.x;
	yaw += rotation.z;
	pitch += rotation.y;
	if (roll > 360) {
		roll = 0;
	}
	if (yaw > 360) {
		yaw = 0;
	}
	if (pitch > 360) {
		pitch = 0;
	}
}

Camera::~Camera()
{
}
