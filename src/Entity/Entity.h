#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "Mesh/Mesh.h"
#include "TextureManager/Texture.h"

namespace EntityS
{
	class Entity
	{
		Mesher::Mesh* mesh;
		TextureS::Texture* texture;
		glm::vec3 position;
		glm::vec3 rotate;
		glm::vec3 scale;
		float degrees;
	public:
		int id;

		Entity(int id, Mesher::Mesh& mesh, TextureS::Texture& texture, glm::vec3 position, glm::vec3 rotate, float degrees, glm::vec3 scale);

		Mesher::Mesh* GetMesh();
		TextureS::Texture* GetTexture();
		glm::vec3 GetPosition();
		glm::vec3 GetRotate();
		glm::vec3 GetScale();
		float GetRotateDegrees();
	};
}