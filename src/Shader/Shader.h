#pragma once
#include <glad/glad.h>
#include <iostream>

namespace ShaderS
{
	class ShaderProgram
	{
	public:
		ShaderProgram(std::string VertexShader, std::string FragmentShader);
		~ShaderProgram();
		ShaderProgram() = delete;

		bool CreateShader(std::string source, GLenum shader_type, GLuint& shader_id);
		void UseShaderProgram();

		void SetShaderProgram(GLuint id);
		GLuint GetShaderProgram();

		bool isCompiled;
	private:
		GLuint shaderProgram;
	};
}