#include "World/World.h"

namespace WorldS
{
	World::World()
	{
		entities.reserve(1000);
	}
	void World::AddEntity(EntityS::Entity& entity)
	{
		entities.push_back(&entity);
	}
	std::vector<EntityS::Entity*>& World::GetEntities()
	{
		return this->entities;
	}
}