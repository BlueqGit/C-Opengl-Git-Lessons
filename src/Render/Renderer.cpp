#include "Renderer.h"


namespace Renderer
{
	Render::Render(ShaderS::Shader& Shader)
	{
		this->Shader = &Shader;
	}

	void Render::DrawWorld(WorldS::World& World, CameraS::Camera& camera)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		this->Shader->UseShaderProgram();

		std::vector<EntityS::Entity*>& entities = World.getEntities();
		EntityS::Entity* tmp_entity;
		
		camera.view = glm::lookAt(camera.cameraPos, camera.cameraPos + camera.cameraFront, camera.cameraUp);

		glUniformMatrix4fv(this->Shader->view_m_loc, 1, GL_FALSE, glm::value_ptr(camera.view));
		glUniformMatrix4fv(this->Shader->projection_m_loc, 1, GL_FALSE, glm::value_ptr(camera.projection));
		glUniform1i(this->Shader->texture_loc, 0);

		for (size_t i = 0; i < entities.size(); i++)
		{
			tmp_entity = entities[i];
			
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, tmp_entity->GetTexture()->GetTextureID());

			camera.model = glm::mat4(1.0f);
			camera.model = glm::translate(camera.model, tmp_entity->GetPosition());
			camera.model = glm::rotate(camera.model, glm::radians(tmp_entity->GetRotateDegrees()), tmp_entity->GetRotate());
			camera.model = glm::scale(camera.model, tmp_entity->GetScale());
			
			glUniformMatrix4fv(this->Shader->model_m_loc, 1, GL_FALSE, glm::value_ptr(camera.model));
			tmp_entity->GetMesh()->MeshDraw();
		}
	}
}