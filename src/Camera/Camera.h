#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

namespace CameraS
{
	class Camera
	{
	public:
		float cameraFov;
		float cameraSpeed;
		glm::vec3 cameraPos;
		glm::vec3 cameraFront;
		glm::vec3 cameraUp;
		//glm::vec3 cameraRight;
		unsigned int width;
		unsigned int height;
		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 projection;

		Camera(float cameraFov, float cameraSpeed, unsigned int width, unsigned int height);
		Camera(const Camera& camera) = delete;
	};
}