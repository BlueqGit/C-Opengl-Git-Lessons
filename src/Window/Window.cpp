#include "Window.h"

namespace Win
{
	Window::Window(int SizeX, int SizeY, char* WinName)
    {
        this->window = nullptr;
        this->WindowName = WinName;
        this->windowSizeX = SizeX;
        this->windowSizeY = SizeY;
        this->windowShouldClose = false;

        if (!glfwInit())
        {
            std::cout << "glfwInit failed!!!" << std::endl;
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        this->window = glfwCreateWindow(this->windowSizeX, this->windowSizeY, WinName, NULL, NULL);
        if (!this->window)
        {
            glfwTerminate();
            std::cerr << "Failed to load Window" << std::endl;
            return;
        }

        glfwMakeContextCurrent(this->window);

        if (!gladLoadGL())
        {
            std::cout << "Can't load glad!" << std::endl;
            glfwTerminate();
            return;
        }

        glEnable(GL_DEPTH_TEST);

        glfwSetWindowUserPointer(this->window, this);
        glfwSetWindowSizeCallback(this->window, glfwWindowSizeCallBack);
        glfwSetKeyCallback(this->window, glfwWindowKeyCallBack);
	}

    void Window::glfwWindowSizeCallBack(GLFWwindow* window, int width, int height)
    {
        Window* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
        self->windowSizeX = width;
        self->windowSizeY = height;
        glViewport(0, 0, self->windowSizeX, self->windowSizeY);
    }

    void Window::glfwWindowKeyCallBack(GLFWwindow* window, int key, int scanmode, int action, int mode)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            Window* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
            self->windowShouldClose = GLFW_TRUE;
            std::cout << "Exite!" << std::endl;
        }
    }

    GLFWwindow* Window::getWindow()
    {
        return this->window;
    }

    bool Window::getWindowShouldClose()
    {
        return this->windowShouldClose;
    }
    
    Window::~Window()
    {
        glfwDestroyWindow(this->window);
        glfwTerminate();
        return;
    }
}