#ifndef _CAMERA_H
#define _CAMERA_H

#pragma once

#include "OpenGL\glew-1.13.0\include\GL\glew.h"

#include "OpenGL\glm\glm\glm.hpp"
#include "DRE_typedef.h"
#include "Frustrum.h"
#include "GameObject.h"

namespace DRE
{
	class Scene;
	class ShaderProgram;

	class Camera : public GameObject
	{
	public:
		Frustrum frustrum;

		U32 windowWidth;
		U32 windowHeight;

		F32 horizontalAngle;
		F32 verticalAngle;
		F32 initialFOV;
		F32 speed;
		F32 mouseSpeed;

		Camera(Scene* scene);
		~Camera();

		virtual void Update(const F32 deltaTime) override;
		virtual void Render() override;

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
		glm::vec3 target;
		glm::vec3 direction;

		glm::vec3 cameraUp;
		glm::vec3 up;
		glm::vec3 cameraRight;

		glm::mat4 projectionMatrix;
		glm::mat4 viewMatrix;

		ShaderProgram* shaderProgram;
	};
}

#endif