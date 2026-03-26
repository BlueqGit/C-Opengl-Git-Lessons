#pragma once
#include "Shader/Shader.h"
#include "Entity/Entity.h"

namespace Renderer
{
	class Render
	{
	public:
		void Draw(Shader::ShaderProgram& ShaderP, EntityS::Entity& Entity);
	};
}