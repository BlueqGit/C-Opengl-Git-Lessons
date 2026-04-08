#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Camera/Camera.h"

namespace WindowS
{
	class Window
	{
		GLFWwindow* window;
		int windowSizeX;
		int windowSizeY;
		char* WindowName;
		bool windowShouldClose;
		CameraS::Camera* camera;
	public:
		Window(int SizeX, int SizeY, char* WinName);
		Window() = delete;
		Window(const Window&) = delete;
		~Window();
		static void glfwWindowSizeCallBack(GLFWwindow* window, int width, int height);
		static void glfwWindowKeyCallBack(GLFWwindow* window, int key, int scanmode, int action, int mode);
		GLFWwindow* getWindow();
		bool getWindowShouldClose();
	};
}