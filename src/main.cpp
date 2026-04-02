#include "Window/Window.h"
#include "Render/Renderer.h"
#include "Reader/Reader.h"
#include "TextureManager/Texture.h"
#include "Entity/Entity.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

float vertixes[] = {
        //x     y      z      r     g     b      T     S
        -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,//bottom right      //задня сторона
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f,//bottom left
         0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 1.0f,//top left
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f,//top right

        -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f,//bottom left       //передня сторона
         0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f,//bottom right
         0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 1.0f,//top right
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 1.0f,//top left
};

unsigned int indices[] = {
    0, 1, 2, 2, 3, 0,
    4, 5, 6, 6, 7, 4,
    0, 4, 7, 7, 3, 0,
    1, 5, 6, 6, 2, 1,
    0, 1, 5, 5, 4, 0,
    3, 7, 6, 6, 2, 3
};

unsigned int width = 500;
unsigned int height = 500;

int main(void)
{
    Win::Window Window(width, height, "My Engine");
	glClearColor(0.7, 0.9, 1, 1);
    
    FileReader::Reader Reader;
    std::string vertex_shader = Reader.GetShaderFile("ShaderFiles/VertexShader.vert");
    std::string fragment_shader = Reader.GetShaderFile("ShaderFiles/FragmentShader.frag");

    Shader::ShaderProgram ShaderP(vertex_shader, fragment_shader);
    Renderer::Render Render(ShaderP, width, height);

    Mesher::Mesh Mesh(vertixes, 8, indices, 36);
    TextureS::Texture Texture("Textures/cat.jpg", 500, 500, 3);

    EntityS::Entity Block(0, Mesh, Texture, glm::vec3(0, 0, 0), glm::vec3(1, 0, 0), 0, glm::vec3(1, 1, 1));

    while (!Window.getWindowShouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_DEPTH_BUFFER_BIT);

        Render.Draw(Block);

        glfwSwapBuffers(Window.getWindow());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}