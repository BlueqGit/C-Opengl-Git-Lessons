#pragma once
#include "Mesh/Mesh.h"
#include "Shader/Shader.h"
#include "TextureManager/Texture.h"


namespace Renderer
{
	class Render
	{
	public:
		void Draw(Mesher::Mesh& Mesh, Shader::ShaderProgram& ShaderP, TextureS::Texture& Texture);
	};
}