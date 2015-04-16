#include "gEntity.h"

namespace BAMF
{
	template<typename T> void gEntity::AddComponent(T* component)
	{
		Components.insert(pair<gComponentTypeId, gComponent*>(T::gComponentTypeId, component));
	}
	gComponent* gEntity::GetComponent(gComponentTypeId typeId)
	{
		return Components[typeId];
	}

	gEntity::gEntity(void)
	{
	}

	gEntity::~gEntity(void)
	{
	}
}
