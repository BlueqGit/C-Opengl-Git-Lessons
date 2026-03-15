#include "ShaderProgram.h"

namespace Render
{
	ShaderProgram::ShaderProgram(const char* VertexShader, const char* FragmentShader)
	{
		GLuint vs;
		GLuint fs;

		if (!CreateShader(VertexShader, GL_VERTEX_SHADER, vs))
		{
			std::cerr << "Vertex shader compilation failed!!!" << std::endl;
			return;
		}
		if (!CreateShader(FragmentShader, GL_FRAGMENT_SHADER, fs))
		{
			std::cerr << "Fragment shader compilation failed!!!" << std::endl;
			glDeleteShader(vs);
			return;
		}

		this->shaderProgram = glCreateProgram();
		glAttachShader(this->shaderProgram, vs);
		glAttachShader(this->shaderProgram, fs);
		glLinkProgram(this->shaderProgram);

		GLint success;
		glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &success);
		if (!success)
		{
			GLchar infoLog[1024];
			glGetProgramInfoLog(this->shaderProgram, 1024, nullptr, infoLog);
			std::cerr << "Log:" << infoLog << std::endl;
			return;
		}
		isCompiled = true;
		glDeleteShader(vs);
		glDeleteShader(fs);
	}

	bool ShaderProgram::CreateShader(const char* source, GLenum shader_type, GLuint& shader_id)
	{
		shader_id = glCreateShader(shader_type);
		glShaderSource(shader_id, 1, &source, nullptr);
		glCompileShader(shader_id);

		GLint success;
		glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
		
		if (success)
		{
			return success;
		}
		else
		{
			GLchar infoLog[1024];
			glGetShaderInfoLog(shader_id, 1024, nullptr, infoLog);
			std::cerr << "Log:" << infoLog << std::endl;
			return false;
		}
	}

	void ShaderProgram::SetShaderProgram(GLuint id)
	{
		this->shaderProgram = id;
	}

	GLuint ShaderProgram::GetShaderProgram()
	{
		return this->shaderProgram;
	}

	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(this->shaderProgram);
	}

	ShaderProgram& ShaderProgram::operator=(ShaderProgram&& ShaderProgram) noexcept
	{
		glDeleteProgram(this->shaderProgram);
		this->shaderProgram = ShaderProgram.shaderProgram;
		isCompiled = ShaderProgram.isCompiled;

		ShaderProgram.isCompiled = false;
		ShaderProgram.shaderProgram = 0;
		return *this;
	}
	ShaderProgram::ShaderProgram(ShaderProgram&& ShaderProgram) noexcept
	{
		this->shaderProgram = ShaderProgram.shaderProgram;
		isCompiled = ShaderProgram.isCompiled;

		ShaderProgram.isCompiled = false;
		ShaderProgram.shaderProgram = 0;
	}
}
