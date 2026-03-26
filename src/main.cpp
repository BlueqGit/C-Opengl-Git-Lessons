#include "Window/Window.h"
#include "Render/Renderer.h"
#include "Reader/Reader.h"
#include "TextureManager/Texture.h"
#include "Entity/Entity.h"

float vertixes[] = {
    //pos               //color             //tex cords
    -0.5f, 0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
    -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
    0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
    0.5f, 0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 1.0f
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
    std::string vertex_shader = Reader.GetShaderFile("ShaderFiles/VertexShader.vert");
    std::string fragment_shader = Reader.GetShaderFile("ShaderFiles/FragmentShader.frag");

    Shader::ShaderProgram ShaderP(vertex_shader, fragment_shader);
    if (!ShaderP.isCompiled)
    {
        std::cerr << "Can't create Shader Program!" << std::endl;
        return -1;
    }

    Mesher::Mesh Mesh(vertixes, 4, indices, 6);

    Renderer::Render Render;

    TextureS::Texture Texture("Textures/1.png", 100, 100, 3);

    EntityS::Entity Block(0, Mesh, Texture, glm::vec3(0, 0, 0));

    while (!Window.getWindowShouldClose())
    {
        Render.Draw(ShaderP, Block);

        glfwSwapBuffers(Window.getWindow());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}