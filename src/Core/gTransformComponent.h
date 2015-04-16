#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

#include "gComponent.h"

using namespace glm;

namespace BAMF
{
	class gTransformComponent : public gComponent
	{
	public:
		static const gComponentTypeId TypeId = 4;

		vec3 position;
		quat rotation;

		gTransformComponent()
		{
			position = vec3(0, 0, 0);
			rotation = quat(1, 0, 0, 0);
		}
		~gTransformComponent(void);
	};
}