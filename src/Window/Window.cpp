#include "Window.h"

namespace WindowS
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
        //glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_FALSE);

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

        glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        glfwSetWindowUserPointer(this->window, this);
        glfwSetWindowSizeCallback(this->window, glfwWindowSizeCallBack);
	}

    void Window::glfwWindowSizeCallBack(GLFWwindow* window, int width, int height)
    {
        Window* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
        self->windowSizeX = width;
        self->windowSizeY = height;
        glViewport(0, 0, self->windowSizeX, self->windowSizeY);
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
    
    void Window::windowClose()
    {
        this->windowShouldClose = true;
    }
}