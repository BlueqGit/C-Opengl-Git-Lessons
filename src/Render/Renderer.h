#pragma once
#include "Shader/Shader.h"
#include "Entity/Entity.h"
#include "World/World.h"
#include "Camera/Camera.h"

namespace Renderer
{
	class Render
	{
		ShaderS::Shader* Shader;
	public:
		Render(ShaderS::Shader& Shader);
		void DrawWorld(WorldS::World& World, CameraS::Camera& camera);
	};
}