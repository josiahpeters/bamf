#pragma once

#include "gTransformComponent.h"

using namespace BAMF;
using namespace System::ComponentModel;

[TypeConverter(ExpandableObjectConverter::typeid)] 
ref class Transform
{

public:

	gTransformComponent* umanaged;
	TreeNode^ node;

	property Vector3^ Position;
	property Quaternion^ Rotation;

	public Transform()
	{
		
	}
	void Set(gTransformComponent* transform)
	{
		unmanaged = transform;

		Position->Set(&umanaged->position);
		Rotation->Set(&umanaged->rotation);
	}	
};

