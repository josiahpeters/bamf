#include "gEntitySystem.h"

namespace BAMF
{
	void gEntitySystem::AddSystem(gSystem* system)
	{
		Systems.push_back(system);
	}	
	map<gEntity*, gComponent*> gEntitySystem::GetEntityMapping(gComponentTypeId typeId)
	{
		return ComponentMappings[typeId];
	}

	gEntity* gEntitySystem::CreateEntity()
	{
		gEntity* entity = new gEntity();
		entity->id = entityId++;
		Entities.insert(pair<int, gEntity*>(entity->id, entity));
		return entity;
	}
	gEntity* gEntitySystem::GetEntity(int id)
	{
		return Entities[id];
	}
	void gEntitySystem::Update(float duration)
	{
		for(int i = 0; i < Systems.size(); i++)
		{
			Systems[i]->Update(duration);
		}
	}

	gEntitySystem::gEntitySystem(void)
	{
		entityId = 1;
	}


	gEntitySystem::~gEntitySystem(void)
	{
	}
}