#include "Renderer.h"


namespace Renderer
{
	void Render::Draw(Shader::ShaderProgram& ShaderP, EntityS::Entity& Entity)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		ShaderP.UseShaderProgram();
		glUniform1i(glGetUniformLocation(ShaderP.GetShaderProgram(), "ourTexture"), 0);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Entity.GetTexture()->GetTextureID());
		Entity.GetMesh()->MeshDraw();
	}
}