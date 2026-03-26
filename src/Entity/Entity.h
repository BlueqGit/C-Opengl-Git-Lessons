#pragma once
#include <glm.hpp>
#include "Mesh/Mesh.h"
#include "TextureManager/Texture.h"

namespace EntityS
{
	class Entity
	{
		Mesher::Mesh* mesh;
		TextureS::Texture* texture;
	public:
		glm::vec3 position;
		int id;

		Entity(int id, Mesher::Mesh& mesh, TextureS::Texture& texture, glm::vec3 position);

		Mesher::Mesh* GetMesh();
		TextureS::Texture* GetTexture();
	};
}