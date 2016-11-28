
#ifndef _included_entity
#define _included_entity

#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>
#include <iostream>
#include "glm\vec3.hpp"
#include "glm\gtc\type_ptr.hpp"
#include "texturedModel.h"



#include <GL\glew.h>



	class Entity {

	public:
		
		Entity() {};
		void IncreaseScale(GLfloat amount) { scale += amount; }
		Entity(texturedModel pModel, glm::vec3 pPosition,
			GLfloat pRotX, GLfloat pRotY, GLfloat pRotZ, GLfloat pScale) {
			model = pModel;
			position = pPosition;
			rotX = pRotX;
			rotY = pRotY;
			rotZ = pRotZ;
			scale = pScale;

		}

		void SetPosition(glm::vec3 pPosition) { position = pPosition; }
		void SetRotation(GLfloat pRotX, GLfloat pRotY, GLfloat pRotZ) { rotX = pRotX; rotY = pRotY; rotZ = pRotZ; }

		texturedModel& getModel() {
			return model;
		}

		const glm::vec3& getPos() {
			return position;
		}

		void setPos(const glm::vec3& pos) {
			position = pos;
		}

		float getRotx() const {
			return rotX;
		}

		void setRotx(float rotx) {
			rotX = rotx;
		}

		float getRoty() const {
			return rotY;
		}

		void setRoty(float roty) {
			rotY = roty;
		}

		float getRotz() const {
			return rotZ;
		}

		void setRotz(float rotz) {
			rotZ = rotz;
		}

		float getScale() const {
			return scale;
		}

		void setScale(float newScale) {
			scale = newScale;
		}

		void IncreasePosition(float x, float y, float z) {
			position = position += glm::vec3(x, y, z);
		}
		void IncreaseRotation(float x, float y, float z) {
			rotX += x;
			rotY += y;
			rotZ += z;

			while (rotX > 360) rotX -= 360;
			while (rotY > 360) rotY -= 360;
			while (rotZ > 360) rotZ -= 360;
		}


	private:
		texturedModel model;
		glm::vec3 position;
		GLfloat rotX, rotY, rotZ;
		GLfloat scale;



};

#endif // _included_entity



