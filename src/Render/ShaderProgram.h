#pragma once
#include <glad/glad.h>
#include <iostream>

namespace Render
{
	class ShaderProgram
	{
	public:
		ShaderProgram(const char* VertexShader, const char* FragmentShader);
		~ShaderProgram();
		ShaderProgram() = delete;
		ShaderProgram(ShaderProgram&) = delete;
		ShaderProgram& operator=(const ShaderProgram&) = delete;
		ShaderProgram& operator=(ShaderProgram&& ShaderProgram) noexcept;
		ShaderProgram(ShaderProgram&& ShaderProgram) noexcept;

		bool CreateShader(const char* source, GLenum shader_type, GLuint& shader_id);

		void SetShaderProgram(GLuint id);
		GLuint GetShaderProgram();
		bool isCompiled;
	private:
		GLuint shaderProgram;
		
	};
}