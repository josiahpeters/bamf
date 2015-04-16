#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

#include "gComponent.h"
#include "gVector.h"
#include "gQuat.h"

using namespace glm;

namespace BAMF
{
	class gCameraComponent : public gComponent
	{
	public:
		static const gComponentTypeId TypeId = 3;

		float rotationX;
		float rotationY;

		vec3 position;

		vec3 movement;

		bool forward;
		bool backward;
		bool left;
		bool right;
		bool up;
		bool faster;

		void UpdateMovement(float duration)
		{
			if(forward)
				movement.z = -1;
			if(backward)
				movement.z = 1;
			if(left)
				movement.x = -1;
			if(right)
				movement.x = 1;
			if(up)			
				movement.y = 1;

			vec3 move = movement * Rotation();

			if(faster)
				position += move * duration * 4.0f;
			else
				position += move * duration;

			movement = vec3(0);
		}
		quat Rotation()
		{
			quat rotation = quat(vec3(0,rotationX, 0));
			return quat(vec3(rotationY, 0, 0)) * rotation;
			//return quat(vec3(rotationY, 0, 0));
		}

		vec3 Lookat()
		{
			vec3 forward(0, 0, -1);
			vec3 direction = forward * Rotation();	
			return position + direction;		
		}

		gCameraComponent()
		{
			movement = vec3(0,0,0);

			forward = false;
			backward = false;
			left = false;
			right = false;
			up = false;
			faster = false;

			rotationX = .15f;
			rotationY = 0.78f;
			position = vec3(0,5,5);
		}
	};
}