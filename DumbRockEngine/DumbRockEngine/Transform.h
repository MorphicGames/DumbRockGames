#ifndef _TRANSFORM_H
#define _TRANSFORM_H
#pragma once

#include "OpenGL\glm\glm\glm.hpp"
namespace DRE {

	class Transform
	{
	public:
		Transform();
		~Transform();

		void Translate(glm::vec3 translate);
		void Rotate(float angleX, float angleY, float angleZ);

		glm::mat4 getFullTransform();

	protected:
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
	};
}

#endif