#include "Renderer.h"

namespace Renderer
{
	void Render::Draw(Mesher::Mesh& Mesh, Shader::ShaderProgram& ShaderP)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		ShaderP.UseShaderProgram();
		Mesh.MeshDraw();
	}
}