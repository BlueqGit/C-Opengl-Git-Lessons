#pragma once
#include <glad/glad.h>
#include <iostream>

namespace ShaderS
{
	class Shader
	{
	public:
		GLint shaderProgram;
		
		GLint model_m_loc;
		GLint view_m_loc;
		GLint projection_m_loc;
		GLint texture_loc;
		Shader(std::string VertexShader, std::string FragmentShader);
		~Shader();
		Shader() = delete;

		bool CreateShader(std::string source, GLenum shader_type, GLuint& shader_id);
		void UseShaderProgram();

		void SetShaderProgram(GLuint id);
		GLuint GetShaderProgram();

		bool isCompiled;
	};
}