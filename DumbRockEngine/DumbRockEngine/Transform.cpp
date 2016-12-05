#include "Transform.h"
#include "OpenGL\glm\glm\gtx\rotate_vector.hpp"

namespace DRE
{
	Transform::Transform()
	{
		position = glm::vec3();
		rotation = glm::vec3();
		scale = glm::vec3();
	}

	void Transform::Rotate(float angleX, float angleY, float angleZ)
	{
		glm::rotateX(rotation, angleX);
		glm::rotateY(rotation, angleY);
		glm::rotateZ(rotation, angleZ);
	}

	void Transform::Translate(glm::vec3 translate)
	{
		position += translate;
	}

	glm::mat4 Transform::getFullTransform()
	{
		//return all 3 things added together into a matrix
	}
}