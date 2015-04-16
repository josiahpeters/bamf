#pragma once

#include <map>
#include <vector>

#include "gEntity.h"
#include "gSystem.h"
#include "gVertexComponent.h"
#include "gShaderComponent.h"
#include "gCameraComponent.h"
#include "gTransformComponent.h"
#include "gVector.h"

using namespace std;

namespace BAMF
{
	class gEntitySystem
	{
		map<int, gEntity*> Entities;
		vector<gSystem*> Systems;
		map<gComponentTypeId, map<gEntity*, gComponent*> > ComponentMappings;
		int entityId;
	public:
		template<typename T> void AddComponent(gEntity* entity, T* component)
		{
			ComponentMappings[T::TypeId].insert(pair<gEntity*, gComponent*>(entity, component));
		}
		map<gEntity*, gComponent*> GetEntityMapping(gComponentTypeId typeId);
		void AddSystem(gSystem* system);		
		gEntity* CreateEntity();
		gEntity* GetEntity(int id);
		void Update(float duration);

		gEntitySystem(void);
		~gEntitySystem(void);
	};
}

