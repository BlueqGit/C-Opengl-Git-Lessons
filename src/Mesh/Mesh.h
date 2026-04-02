#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace Mesher
{
	class Mesh
	{
		GLuint vbo;
		GLuint vao;
		GLuint ebo;
		float* vertixes;
		GLint count_vertixes;
		GLint count_indices;
	public:
		Mesh(float* vertixes_tmp, GLint count_vertixes_tmp, unsigned int* indices, GLint count_indices_tmp);
		~Mesh();
		void MeshDraw();
		GLuint GetVao();
	};
}