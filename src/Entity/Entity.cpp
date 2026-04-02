#include "Entity/Entity.h"

namespace EntityS
{
	Entity::Entity(int id, Mesher::Mesh& mesh, TextureS::Texture& texture, glm::vec3 position, glm::vec3 rotate, int degrees, glm::vec3 scale)
	{
		this->id = id;
		this->position = position;
		this->rotate = rotate;
		this->degrees = degrees;
		this->scale = scale;
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
	glm::vec3 Entity::GetPosition()
	{
		return this->position;
	}
	glm::vec3 Entity::GetRotate()
	{
		return this->rotate;
	}
	glm::vec3 Entity::GetScale()
	{
		return this->scale;
	}
	int Entity::GetRotateDegrees()
	{
		return this->degrees;
	}
}