#include "Camera/Camera.h"

namespace CameraS
{
	Camera::Camera(WindowS::Window& window, unsigned int width, unsigned int height, float sensitivity, float cameraFov, float cameraSpeed)
	{
		this->window = &window;

		this->width = width;
		this->height = height;
		this->cameraFov = cameraFov;
		this->cameraSpeed = cameraSpeed;
		this->sensitivity = sensitivity;

		this->lastX = this->width / 2;
		this->lastY = this->height / 2;
		this->yaw = -90.0f;
		this->pitch = 0.0f;
		this->xoffset = 0.0f;
		this->yoffset = 0.0f;
		this->firstMouse = true;
		
		this->cameraPos = glm::vec3(0.0f, 0.0f, 10.0f);
		this->cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
		this->cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

		this->model = glm::mat4(1.0f);
		this->view = glm::mat4(1.0f);
		this->projection = glm::perspective(glm::radians(this->cameraFov), float(this->width) / float(this->height), 0.1f, 100.0f);

		glfwSetWindowUserPointer(this->window->getWindow(), this);
		glfwSetCursorPosCallback(this->window->getWindow(), mouse_callback);
	}

	void Camera::mouse_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Camera* self = static_cast<Camera*>(glfwGetWindowUserPointer(window));

		if (self->firstMouse)
		{
			self->lastX = xpos;
			self->lastY = ypos;
			self->firstMouse = false;
		}

		float xoffset = xpos - self->lastX;
		float yoffset = self->lastY - ypos;
		self->lastX = xpos;
		self->lastY = ypos;

		xoffset *= self->sensitivity;
		yoffset *= self->sensitivity;

		self->yaw += xoffset;
		self->pitch += yoffset;

		if (self->pitch > 89.0f) self->pitch = 89.0f;
		if (self->pitch < -89.0f) self->pitch = -89.0f;
	}
}