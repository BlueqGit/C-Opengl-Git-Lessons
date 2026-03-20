#pragma once
#include <glad/glad.h>
#include <iostream>

namespace Shader
{
	class ShaderProgram
	{
	public:
		ShaderProgram(const char* VertexShader, const char* FragmentShader);
		~ShaderProgram();
		ShaderProgram() = delete;

		bool CreateShader(const char* source, GLenum shader_type, GLuint& shader_id);
		void UseShaderProgram();

		void SetShaderProgram(GLuint id);
		GLuint GetShaderProgram();

		bool isCompiled;
	private:
		GLuint shaderProgram;
	};
}