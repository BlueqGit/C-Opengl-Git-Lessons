#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace Mesher
{
	class Mesh
	{
		GLuint vertex_vbo;
		GLuint colors_vbo;
		GLuint vao;
		float* vertixes;
		float* colors;
		GLint count_vertixes;
	public:
		Mesh(float* vertixes_tmp, float* colors_tmp, GLint count_vertixes_tmp);
		~Mesh();
		void MeshDraw();
	};
}