#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int windowSizeX = 640;
int windowSizeY = 480;



int main(void)
{
    if (!glfwInit())
    { 
        std::cout << "glfwInit failed!!!" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(windowSizeX, windowSizeY, "My first game", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
	
	if(!gladLoadGL())
	{
        std::cout << "Can't load glad!" << std::endl;
		return -1;
	}
	
	glClearColor(0, 1, 1, 1);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);



        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}