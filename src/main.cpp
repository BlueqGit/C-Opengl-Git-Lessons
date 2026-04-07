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
    -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f,//bottom left
     0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f,//bottom right
     0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 1.0f,//top right
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 1.0f,//top left           //FRONT SIDE

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f,//bottom left
    -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f,//bottom right
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f,//top right
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 1.0f,//top left           //LEFT SIDE

     0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f,//bottom left
    -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,//bottom right
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f,//top right
     0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 1.0f,//top left           //BACK SIDE

     0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f,//bottom left
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f,//bottom right
     0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f,//top right
     0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 1.0f,//top left           //RIGHT SIDE

    -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f,//bottom left
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f,//bottom right
     0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f,//top right
    -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 1.0f,//top left           //BOTTOM SIDE

     0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 0.0f,//bottom right
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f,//bottom left
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 1.0f,//top left
     0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f,//top right          //TOP SIDE
};

unsigned int indices[] = {
    0, 1, 2, 2, 3, 0,         //передня сторона
    4, 5, 6, 6, 7, 4,         //ліва сторона
    8, 9, 10, 10, 11, 8,      //задня сторона
    12, 13, 14, 14, 15, 12,   //права сторона
    16, 17, 18, 18, 19, 16,   //нижня сторона
    20, 21, 22, 22, 23, 20    //верхня сторона
};

unsigned int width = 500;
unsigned int height = 500;

int main(void)
{
    Win::Window Window(width, height, "My Engine");
    FileReader::Reader Reader;
    std::string vertex_shader = Reader.GetShaderFile("ShaderFiles/VertexShader.vert");
    std::string fragment_shader = Reader.GetShaderFile("ShaderFiles/FragmentShader.frag");
    ShaderS::ShaderProgram ShaderP(vertex_shader, fragment_shader);
    Renderer::Render Render(ShaderP, width, height);
    WorldS::World World;

    Mesher::Mesh Mesh(vertixes, 24, indices, 36);
    TextureS::Texture Texture("Textures/cat.jpg", 500, 500, 3);

    EntityS::Entity Block1(0, Mesh, Texture, glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), 30, glm::vec3(2.0f, 1.0f, 1.0f));
    EntityS::Entity Block2(0, Mesh, Texture, glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 120, glm::vec3(1.0f, 1.5f, 2.0f));

    World.AddEntity(Block1);
    World.AddEntity(Block2);

    glClearColor(0.7f, 0.9f, 1.0f, 1.0f);
    while (!Window.getWindowShouldClose())
    {
        Render.DrawWorld(World);

        glfwSwapBuffers(Window.getWindow());
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}