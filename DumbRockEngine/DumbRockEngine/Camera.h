#ifndef _CAMERA_H
#define _CAMERA_H

#pragma once

#include <glew.h>
#include <glm.hpp>

#include "DRE_typedef.h"
#include "Frustrum.h"

namespace DRE
{
	class Camera
	{
	public:
		Frustrum frustrum;

		U32 windowWidth;
		U32 windowHeight;

		F32 horizontalAngle;
		F32 verticalAngle;
		F32 initialFOV;

		Camera();
		~Camera();

		void Update();
		void Render();

		void CalculateCameraMatrix();

		inline void SetPosition(const glm::vec3& newPosition) {
			position = newPosition;
		}
		inline void SetUpVector(const glm::vec3& newUpVector) {
			up = newUpVector;
		}
		inline void SetDirectionVector(const glm::vec3& newDirectionVector) {
			direction = newDirectionVector;
		}

	protected:
		glm::vec3 position;
		glm::vec3 direction;
		glm::vec3 up;

		glm::mat4 projectionMatrix;
		glm::mat4 viewMatrix;
	};
}

#endif