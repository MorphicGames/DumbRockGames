#include "Camera.h"

#include "OpenGL/glm/glm/gtc/matrix_transform.hpp"

#include "Game.h"

namespace DRE
{
	Camera::Camera(Scene* scene)
		: GameObject(scene)
	{
		gameObject = this;

		windowWidth = GAME.gameWindow->GetWindowWidth();
		windowHeight = GAME.gameWindow->GetWindowHeight();

		horizontalAngle = 3.14f;
		verticalAngle = 0.0f;
		initialFOV = 45.0f;

		mouseSpeed = 0.000001f;
		speed = 4.0f;
	}

	Camera::~Camera()
	{

	}

	void Camera::Update(const F32 deltaTime)
	{
		glm::vec2 mousePosition;

		mousePosition.x = INPUT_MANAGER.motionEvent.x;
		mousePosition.y = INPUT_MANAGER.motionEvent.y;

		direction = glm::vec3(
			cos(verticalAngle) * sin(horizontalAngle),
			sin(verticalAngle),
			cos(verticalAngle) * cos(horizontalAngle)
		);

		glm::vec3 right = glm::vec3(
			sin(horizontalAngle - 3.14f / 2.0f),
			0.0f,
			cos(horizontalAngle - 3.14f / 2.0f)
		);

		up = glm::cross(right, direction);

		if (INPUT_MANAGER.IsKeyDown(SDLK_w)) {
			gameObject->transform.Translate(direction * deltaTime * speed);
		}
		else if (INPUT_MANAGER.IsKeyDown(SDLK_s)) {
			gameObject->transform.Translate(-direction * deltaTime * speed);
		}
		else if (INPUT_MANAGER.IsKeyDown(SDLK_a)) {
			gameObject->transform.Translate(-right * deltaTime * speed);
		}
		else if (INPUT_MANAGER.IsKeyDown(SDLK_d)) {
			gameObject->transform.Translate(right * deltaTime * speed);
		}
	}

	void Camera::Render()
	{
		projectionMatrix = glm::perspective(initialFOV, (F32)windowWidth / windowHeight, 0.1f, 50.0f);
		viewMatrix = glm::lookAt(position, position + direction, up);

		
	}

	void Camera::CalculateCameraMatrix()
	{

	}
}
