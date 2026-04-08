cmake_minimum_required(VERSION 4.3 FATAL_ERROR)
project(NullEngine)

set(CMAKE_CXX_STANDARD 17)

file(GLOB TEXTURE_FILES "src/Textures/*.png" "src/Textures/*.jpg")

set(ALL_SOURCES
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
    src/ShaderFiles/FragmentShader.frag
    src/ShaderFiles/VertexShader.vert
    src/TextureManager/Texture.cpp
    src/TextureManager/Texture.h
    src/TextureManager/stb_image.cpp
    src/TextureManager/stb_image.h
    src/World/World.cpp
    src/World/World.h
    src/Entity/Entity.cpp
    src/Entity/Entity.h
    src/Camera/Camera.cpp
    src/Camera/Camera.h
    ${TEXTURE_FILES}
)

add_executable(${PROJECT_NAME} ${ALL_SOURCES})

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" PREFIX "Source Files" FILES ${ALL_SOURCES})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/external/glm)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/src/ShaderFiles" DESTINATION "${CMAKE_BINARY_DIR}")
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Textures"
        "${CMAKE_BINARY_DIR}/Textures"
    COMMENT "Copying textures to build directory..."
)







