#include "Renderer.h"


namespace Renderer
{
	Render::Render(Shader::ShaderProgram& ShaderP, unsigned int width, unsigned int height)
	{
		this->model = glm::mat4(1.0f);
		this->view = glm::mat4(1.0f);
		this->width = width;
		this->height = height;
		this->ShaderProgram = ShaderP.GetShaderProgram();
		this->model_m_loc = glGetUniformLocation(ShaderP.GetShaderProgram(), "model");
		this->view_m_loc = glGetUniformLocation(ShaderP.GetShaderProgram(), "view");
		this->projection_m_loc = glGetUniformLocation(ShaderP.GetShaderProgram(), "projection");
	}

	void Render::Draw(EntityS::Entity& Entity)
	{
		glUseProgram(this->ShaderProgram);
		glUniform1i(glGetUniformLocation(this->ShaderProgram, "ourTexture"), 0);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Entity.GetTexture()->GetTextureID());

		this->model = glm::mat4(1.0f);
		this->view = glm::mat4(1.0f);

		this->model = glm::translate(this->model, Entity.GetPosition());
		this->model = glm::rotate(this->model, glm::radians((float)Entity.GetRotateDegrees()), Entity.GetRotate());

		this->view = glm::translate(this->view, glm::vec3(0.0f, 0.0f, -5.0f));
		this->projection = glm::perspective(glm::radians(45.0f), float(this->width) / float(this->height), 0.1f, 100.0f);

		glUniformMatrix4fv(this->model_m_loc, 1, GL_FALSE, glm::value_ptr(this->model));
		glUniformMatrix4fv(this->view_m_loc, 1, GL_FALSE, glm::value_ptr(this->view));
		glUniformMatrix4fv(this->projection_m_loc, 1, GL_FALSE, glm::value_ptr(this->projection));

		Entity.GetMesh()->MeshDraw();
	}
}