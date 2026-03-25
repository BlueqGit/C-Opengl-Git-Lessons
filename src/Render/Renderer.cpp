#include "Renderer.h"

namespace Renderer
{
	void Render::Draw(Mesher::Mesh& Mesh, Shader::ShaderProgram& ShaderP, TextureS::Texture& Texture)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		ShaderP.UseShaderProgram();
		glUniform1i(glGetUniformLocation(ShaderP.GetShaderProgram(), "ourTexture"), 0);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Texture.GetTextureID());
		Mesh.MeshDraw();
	}
}