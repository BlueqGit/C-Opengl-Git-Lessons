#include "Window/Window.h"
#include "Render/Renderer.h"
#include "Reader/Reader.h"
#include "TextureManager/Texture.h"
#include "Entity/Entity.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

float vertixes[] = {
        -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 0.0f,

        -0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
};

//float vertixes[] = {
//    //pos               //color             //tex cords
//    -0.5f, 0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
//    -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
//    0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
//    0.5f, 0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 1.0f
//};


unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3
};

float width = 500;
float height = 500;

int main(void)
{
    Win::Window Window(width, height, "My engine");
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

    Mesher::Mesh Mesh(vertixes, 36, indices, 6);
    Renderer::Render Render;
    TextureS::Texture Texture("Textures/1.png", 100, 100, 3);
    EntityS::Entity Block(0, Mesh, Texture, glm::vec3(1, 0, 0));

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection;
    GLint model_m_loc = glGetUniformLocation(ShaderP.GetShaderProgram(), "model");
    GLint view_m_loc = glGetUniformLocation(ShaderP.GetShaderProgram(), "view");
    GLint projection_m_loc = glGetUniformLocation(ShaderP.GetShaderProgram(), "projection");

    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1, 0, 0));
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    projection = glm::perspective(glm::radians(45.0f), width / height, 0.1f, 100.0f);

    float time;

    while (!Window.getWindowShouldClose())
    {
        time = glfwGetTime();
        model = glm::rotate(model, glm::radians(float(sin(time) * 3)), glm::vec3(0, 0, 1));
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, sin(time) / 500));

        glUniformMatrix4fv(model_m_loc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(view_m_loc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projection_m_loc, 1, GL_FALSE, glm::value_ptr(projection));

        Render.Draw(ShaderP, Block);

        glfwSwapBuffers(Window.getWindow());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}