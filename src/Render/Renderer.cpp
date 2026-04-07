#include "Renderer.h"


namespace Renderer
{
	Render::Render(ShaderS::ShaderProgram& ShaderP, unsigned int width, unsigned int height)
	{
		this->width = width;
		this->height = height;
		this->model = glm::mat4(1.0f);
		this->view = glm::mat4(1.0f);
		this->view = glm::translate(this->view, glm::vec3(0.0f, 0.0f, -5.0f));
		this->projection = glm::perspective(glm::radians(45.0f), float(this->width) / float(this->height), 0.1f, 100.0f);
		this->ShaderProgram = &ShaderP;
		this->texture_loc = glGetUniformLocation(this->ShaderProgram->GetShaderProgram(), "ourTexture");
		this->model_m_loc = glGetUniformLocation(this->ShaderProgram->GetShaderProgram(), "model");
		this->view_m_loc = glGetUniformLocation(this->ShaderProgram->GetShaderProgram(), "view");
		this->projection_m_loc = glGetUniformLocation(this->ShaderProgram->GetShaderProgram(), "projection");
	}

	void Render::DrawEntity(EntityS::Entity& Entity)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		this->ShaderProgram->UseShaderProgram();
		glUniform1i(this->texture_loc, 0);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Entity.GetTexture()->GetTextureID());

		this->model = glm::mat4(1.0f);
		this->model = glm::translate(this->model, Entity.GetPosition());
		this->model = glm::rotate(this->model, glm::radians(float(sin(glfwGetTime())* Entity.GetRotateDegrees())), Entity.GetRotate());
		this->model = glm::scale(this->model, Entity.GetScale());

		glUniformMatrix4fv(this->model_m_loc, 1, GL_FALSE, glm::value_ptr(this->model));
		glUniformMatrix4fv(this->view_m_loc, 1, GL_FALSE, glm::value_ptr(this->view));
		glUniformMatrix4fv(this->projection_m_loc, 1, GL_FALSE, glm::value_ptr(this->projection));

		Entity.GetMesh()->MeshDraw();
	}

	void Render::DrawWorld(WorldS::World& World)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		this->ShaderProgram->UseShaderProgram();

		std::vector<EntityS::Entity*>& entities = World.GetEntities();
		EntityS::Entity* tmp_entity;

		glUniformMatrix4fv(this->view_m_loc, 1, GL_FALSE, glm::value_ptr(this->view));
		glUniformMatrix4fv(this->projection_m_loc, 1, GL_FALSE, glm::value_ptr(this->projection));
		glUniform1i(this->texture_loc, 0);

		for (size_t i = 0; i < entities.size(); i++)
		{
			tmp_entity = entities[i];
			
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, tmp_entity->GetTexture()->GetTextureID());

			this->model = glm::mat4(1.0f);
			this->model = glm::translate(this->model, tmp_entity->GetPosition());
			this->model = glm::rotate(this->model, glm::radians(float(sin(glfwGetTime()) * tmp_entity->GetRotateDegrees())), tmp_entity->GetRotate());
			this->model = glm::scale(this->model, tmp_entity->GetScale());

			glUniformMatrix4fv(this->model_m_loc, 1, GL_FALSE, glm::value_ptr(this->model));
			tmp_entity->GetMesh()->MeshDraw();
		}
	}
}