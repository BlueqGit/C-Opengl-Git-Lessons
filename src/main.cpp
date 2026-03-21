#include "Window/Window.h"
#include "Render/Renderer.h"
#include "Reader/Reader.h"

float vertixes[] = {
    //pos               //color
    -0.5f, 0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
    0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,
    0.5f, 0.5f, 0.0f,   0.0f, 1.0f, 0.0f
};

unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3
};

int main(void)
{
    Win::Window Window(500, 500, "My engine");
	glClearColor(0.7, 0.9, 1, 1);
    
    FileReader::Reader Reader;
    std::string vertex_shader = Reader.GetShaderFile("C:/Users/Vitaly/Desktop/NullEngine/src/ShaderFiles/VertexShader.txt");
    std::string fragment_shader = Reader.GetShaderFile("C:/Users/Vitaly/Desktop/NullEngine/src/ShaderFiles/FragmentShader.txt");

    Shader::ShaderProgram ShaderP(vertex_shader, fragment_shader);
    if (!ShaderP.isCompiled)
    {
        std::cerr << "Can't create Shader Program!" << std::endl;
        return -1;
    }

    Mesher::Mesh Mesh(vertixes, 4, indices, 6);

    Renderer::Render Render;

    while (!Window.getWindowShouldClose())
    {
        Render.Draw(Mesh, ShaderP);


        glfwSwapBuffers(Window.getWindow());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}