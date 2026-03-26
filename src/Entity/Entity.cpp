#include "Entity/Entity.h"

namespace EntityS
{
	Entity::Entity(int id, Mesher::Mesh& mesh, TextureS::Texture& texture, glm::vec3 position)
	{
		this->id = id;
		this->position = position;
		this->mesh = &mesh;
		this->texture = &texture;
	}

	Mesher::Mesh* Entity::GetMesh()
	{
		return this->mesh;
	}
	TextureS::Texture* Entity::GetTexture()
	{
		return this->texture;
	}
}