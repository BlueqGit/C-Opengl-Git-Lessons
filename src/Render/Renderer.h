#pragma once
#include "Mesh/Mesh.h"
#include "Shader/Shader.h"


namespace Renderer
{
	class Render
	{
	public:
		void Draw(Mesher::Mesh& Mesh, Shader::ShaderProgram& ShaderP);
	};
}