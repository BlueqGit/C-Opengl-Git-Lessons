#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Render/ShaderProgram.h"

int windowSizeX = 640;
int windowSizeY = 480;

float vertixes[] = {
    -0.5f, 0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,

    -0.5f, 0.5f, 0.0f,
    0.5f, 0.5f, 0.0f,
    0.5f, -0.5f, 0.0f
};
float vertixes_color[] = {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f,

    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f
};

const char* vertex_shader =
    "#version 460\n"
    "layout(location = 0) in vec3 vertex_position;\n"
    "layout(location = 1) in vec3 vertex_color;\n"
    "out vec3 color;\n"
    "void main(){"
    "color = vertex_color;"
    "gl_Position = vec4(vertex_position, 1.0);"
    "}";

const char* fragment_shader =
    "#version 460\n"
    "in vec3 color;"
    "out vec4 fragment_color;"
    "void main() {"
    "fragment_color = vec4(color, 1.0);"
    "}";

void glfwWindowSizeCallBack(GLFWwindow* window, int width, int height);
void glfwWindowKeyCallBack(GLFWwindow* window, int key, int scanmode, int action, int mode);

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
    glfwSetWindowSizeCallback(window, glfwWindowSizeCallBack);
    glfwSetKeyCallback(window, glfwWindowKeyCallBack);

    glfwMakeContextCurrent(window);
    

	if(!gladLoadGL())
	{
        std::cout << "Can't load glad!" << std::endl;
		return -1;
	}
	glClearColor(0.7, 0.9, 1, 1);

    Render::ShaderProgram ShaderProgram(vertex_shader, fragment_shader);
    if (!ShaderProgram.isCompiled)
    {
        std::cerr << "Can't create Shader Program!" << std::endl;
        return -1;
    }

    GLuint vertex_vbo = 0;
    glGenBuffers(1, &vertex_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertixes), vertixes, GL_STATIC_DRAW);
    GLuint colors_vbo = 0;
    glGenBuffers(1, &colors_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, colors_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertixes_color), vertixes_color, GL_STATIC_DRAW);

    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colors_vbo);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);



    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(ShaderProgram.GetShaderProgram());
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void glfwWindowSizeCallBack(GLFWwindow* window, int width, int height)
{
    windowSizeX = width;
    windowSizeY = height;
    glViewport(0, 0, windowSizeX, windowSizeY);
}

void glfwWindowKeyCallBack(GLFWwindow* window, int key, int scanmode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
        std::cout << "normal EXIT!!!" << std::endl;
    }
}