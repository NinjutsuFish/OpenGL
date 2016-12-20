#pragma once
#include "glm\vec3.hpp"
#include <iostream>

class Camera
{
public:
	Camera();
	~Camera();
	float getYaw() { return yaw; }
	float getPitch() { return pitch; }
	float getRoll() { return roll; }
	glm::vec3 getPostiton() { return position; }
	void MoveCamera(glm::vec3 direction,float amount);
	void rotateCamera(glm::vec3 rotation);

private:
	glm::vec3 position = glm::vec3(0, 0, 0);
	float yaw;//left or right of camera
	float pitch;// height of camera
	float roll; //tilted to side if 180 camera upside down#

};

