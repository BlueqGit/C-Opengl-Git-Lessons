#include "Window/Window.h"
#include "Render/Renderer.h"
#include "Reader/Reader.h"
#include "TextureManager/Texture.h"
#include "Entity/Entity.h"
#include "Camera/Camera.h"

float vertixes[] = {
    //x     y      z      T     S
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,//bottom left
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,//bottom right
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,//top right
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,//top left           //FRONT SIDE

    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,//bottom left
    -0.5f, -0.5f,  0.5f,  1.0f, 0.0f,//bottom right
    -0.5f,  0.5f,  0.5f,  1.0f, 1.0f,//top right
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,//top left           //LEFT SIDE

     0.5f, -0.5f, -0.5f,  0.0f, 0.0f,//bottom left
    -0.5f, -0.5f, -0.5f,  1.0f, 0.0f,//bottom right
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,//top right
     0.5f,  0.5f, -0.5f,  0.0f, 1.0f,//top left           //BACK SIDE

     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,//bottom left
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,//bottom right
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,//top right
     0.5f,  0.5f,  0.5f,  0.0f, 1.0f,//top left           //RIGHT SIDE

    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,//bottom left
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,//bottom right
     0.5f, -0.5f,  0.5f,  1.0f, 1.0f,//top right
    -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,//top left           //BOTTOM SIDE

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,//bottom right
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,//bottom left
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,//top left
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,//top right          //TOP SIDE
};

unsigned int indices[] = {
    0, 1, 2, 2, 3, 0,         //передня сторона
    4, 5, 6, 6, 7, 4,         //ліва сторона
    8, 9, 10, 10, 11, 8,      //задня сторона
    12, 13, 14, 14, 15, 12,   //права сторона
    16, 17, 18, 18, 19, 16,   //нижня сторона
    20, 21, 22, 22, 23, 20    //верхня сторона
};

unsigned int width = 1920;
unsigned int height = 1080;
float deltaTime = 0.0f;
float lastFrame = 0.0f;
float currentFrame;

void processInput(GLFWwindow* window, float deltaTime, CameraS::Camera& camera);

int main(void)
{
    
    WindowS::Window Window(width, height, "My Engine");
    FileReader::Reader Reader;
    std::string vertex_shader = Reader.GetShaderFile("ShaderFiles/VertexShader.vert");
    std::string fragment_shader = Reader.GetShaderFile("ShaderFiles/FragmentShader.frag");
    ShaderS::Shader Shader(vertex_shader, fragment_shader);
    Renderer::Render Render(Shader);
    WorldS::World World;

    Mesher::Mesh Mesh(vertixes, 24, indices, 36);
    TextureS::Texture Texture("Textures/cat.jpg", 500, 500, 3);

    CameraS::Camera camera(90.0f, 5.0f, width, height);
    EntityS::Entity Block1(0, Mesh, Texture, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), 0, glm::vec3(1.0f, 1.0f, 1.0f));
    EntityS::Entity Block2(0, Mesh, Texture, glm::vec3(0.0f, 2.0f, 2.0f), glm::vec3(1.0f, 1.0f, 1.0f), 0, glm::vec3(1.0f, 1.0f, 1.0f));
    EntityS::Entity Block3(0, Mesh, Texture, glm::vec3(2.0f, -2.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), 0, glm::vec3(1.0f, 1.0f, 1.0f));
    EntityS::Entity Block4(0, Mesh, Texture, glm::vec3(5.0f, -2.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), 0, glm::vec3(1.0f, 1.0f, 1.0f));
    EntityS::Entity Block5(0, Mesh, Texture, glm::vec3(0.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 0, glm::vec3(1.0f, 1.0f, 1.0f));
    EntityS::Entity Block6(0, Mesh, Texture, glm::vec3(2.0f, 2.0f, 2.0f), glm::vec3(1.0f, 1.0f, 1.0f), 0, glm::vec3(1.0f, 1.0f, 1.0f));
    EntityS::Entity Block7(0, Mesh, Texture, glm::vec3(2.0f, -2.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 0, glm::vec3(1.0f, 1.0f, 1.0f));
    EntityS::Entity Block8(0, Mesh, Texture, glm::vec3(5.0f, -2.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 0, glm::vec3(1.0f, 1.0f, 1.0f));

    World.AddEntity(Block1);
    World.AddEntity(Block2);
    World.AddEntity(Block3);
    World.AddEntity(Block4);
    World.AddEntity(Block5);
    World.AddEntity(Block6);
    World.AddEntity(Block7);
    World.AddEntity(Block8);

    glClearColor(0.7f, 0.9f, 1.0f, 1.0f);
    while (!Window.getWindowShouldClose())
    {
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        Render.DrawWorld(World, camera);

        processInput(Window.getWindow(), deltaTime, camera);
        glfwSwapBuffers(Window.getWindow());
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}


void processInput(GLFWwindow* window, float deltaTime, CameraS::Camera& camera)
{
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        camera.cameraPos += camera.cameraSpeed * camera.cameraFront * deltaTime;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        camera.cameraPos -= camera.cameraSpeed * camera.cameraFront * deltaTime;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        camera.cameraPos -= glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * camera.cameraSpeed * deltaTime;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        camera.cameraPos += glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * camera.cameraSpeed * deltaTime;
    }
}