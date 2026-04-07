#pragma once
#include "Entity/Entity.h"

namespace WorldS
{
	class World
	{
		std::vector<EntityS::Entity*> entities;
	public:
		World();
		void AddEntity(EntityS::Entity& entity);
		std::vector<EntityS::Entity*>& GetEntities();
	};
}