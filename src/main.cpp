#include "Shader/Shader.h"
#include "Window/Window.h"
#include "Mesh/Mesh.h"

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

int main(void)
{
    Win::Window Window(500, 500, "My engine");
	glClearColor(0.7, 0.9, 1, 1);

    Shader::ShaderProgram ShaderP(vertex_shader, fragment_shader);
    if (!ShaderP.isCompiled)
    {
        std::cerr << "Can't create Shader Program!" << std::endl;
        return -1;
    }

    Mesher::Mesh Mesh(vertixes, vertixes_color, 6);

    while (!Window.getWindowShouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);

        ShaderP.UseShaderProgram();
        Mesh.MeshDraw();

        glfwSwapBuffers(Window.getWindow());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}