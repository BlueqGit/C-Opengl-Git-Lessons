cmake_minimum_required(VERSION 4.3 FATAL_ERROR)
set(PROJECT_NAME git-test)
project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} src/main.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORGE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORGE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORGE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORGE)

add_subdirectory(C:/Users/Vitaly/Desktop/git-test/external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)