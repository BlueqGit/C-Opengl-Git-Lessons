#include "Shader.h"

namespace ShaderS
{
	Shader::Shader(std::string VertexShader, std::string FragmentShader)
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


		this->texture_loc = glGetUniformLocation(this->shaderProgram, "ourTexture");
		this->model_m_loc = glGetUniformLocation(this->shaderProgram, "model");
		this->view_m_loc = glGetUniformLocation(this->shaderProgram, "view");
		this->projection_m_loc = glGetUniformLocation(this->shaderProgram, "projection");

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

	bool Shader::CreateShader(std::string source, GLenum shader_type, GLuint& shader_id)
	{
		const char* src = source.c_str();
		shader_id = glCreateShader(shader_type);
		glShaderSource(shader_id, 1, &src, nullptr);
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

	void Shader::SetShaderProgram(GLuint id)
	{
		this->shaderProgram = id;
	}

	GLuint Shader::GetShaderProgram()
	{
		return this->shaderProgram;
	}

	Shader::~Shader()
	{
		glDeleteProgram(this->shaderProgram);
	}

	void Shader::UseShaderProgram()
	{
		glUseProgram(this->shaderProgram);
	}
}
