#pragma once
#include "Shader/Shader.h"
#include "Entity/Entity.h"
#include "World/World.h"

namespace Renderer
{
	class Render
	{
		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 projection;
		GLint model_m_loc;
		GLint view_m_loc;
		GLint projection_m_loc;
		GLint texture_loc;
		ShaderS::ShaderProgram* ShaderProgram;
		unsigned int width;
		unsigned int height;
	public:
		Render(ShaderS::ShaderProgram& ShaderP, unsigned int width, unsigned int height);
		void DrawEntity(EntityS::Entity& Entity);
		void DrawWorld(WorldS::World& World);
	};
}