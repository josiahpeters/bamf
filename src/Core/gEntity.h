#pragma once

#include <map>

#include "gComponent.h"

using namespace std;

namespace BAMF
{
	class gEntity
	{
		map<gComponentTypeId, gComponent*> Components;
	public:
		int id;
		template<typename T> void AddComponent(T* component);
		gComponent* GetComponent(gComponentTypeId typeId);
		gEntity(void);
		~gEntity(void);
	};

}

