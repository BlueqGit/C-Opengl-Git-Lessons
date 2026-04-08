#include "Camera/Camera.h"

namespace CameraS
{
	Camera::Camera(float cameraFov, float cameraSpeed, unsigned int width, unsigned int height)
	{
		this->cameraFov = cameraFov;
		this->cameraSpeed = cameraSpeed;
		this->width = width;
		this->height = height;
		this->cameraPos = glm::vec3(0.0f, 0.0f, 10.0f);
		this->cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
		this->cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
		this->model = glm::mat4(1.0f);
		this->view = glm::mat4(1.0f);
		this->projection = glm::perspective(glm::radians(this->cameraFov), float(this->width) / float(this->height), 0.1f, 100.0f);
	}
}