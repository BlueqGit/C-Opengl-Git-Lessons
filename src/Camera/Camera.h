#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "Window/Window.h"

namespace CameraS
{
	class Camera
	{
	public:
		unsigned int width;
		unsigned int height;
		float cameraFov;
		float cameraSpeed;
		float sensitivity;

		float yaw;
		float pitch;
		float lastX;
		float lastY;
		float xoffset;
		float yoffset;

		bool firstMouse;

		glm::vec3 cameraPos;
		glm::vec3 cameraFront;
		glm::vec3 cameraUp;
		
		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 projection;

		WindowS::Window* window;

		Camera(WindowS::Window& window, unsigned int width, unsigned int height, float sensitivity, float cameraFov, float cameraSpeed);
		Camera(const Camera& camera) = delete;
		static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	};
}