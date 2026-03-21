cmake_minimum_required(VERSION 4.3 FATAL_ERROR)
set(PROJECT_NAME NullEngine)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} 
src/main.cpp 
src/Shader/Shader.cpp 
src/Shader/Shader.h 
src/Window/Window.cpp 
src/Window/Window.h 
src/Render/Renderer.cpp 
src/Render/Renderer.h 
src/Mesh/Mesh.cpp 
src/Mesh/Mesh.h
src/Reader/Reader.cpp 
src/Reader/Reader.h
src/ShaderFiles/FragmentShader.txt 
src/ShaderFiles/VertexShader.txt)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORGE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORGE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORGE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORGE)

target_include_directories(NullEngine PRIVATE src)
add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)