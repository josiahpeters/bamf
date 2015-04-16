#pragma once

#include <glm/glm.hpp>

using namespace glm;
using namespace BAMF;
using namespace System::ComponentModel;

[TypeConverter(ExpandableObjectConverter::typeid)] 
ref class Vector3
{

public:
	vec3* unmanaged;
	//Vector3^ unmanaged;
	property float X 
	{
		float get()
		{
			return unmanaged->x;
		}
		void set(float value)
		{
			unmanaged->x = value;
		}
	}
	property float Y
	{
		float get()
		{
			return unmanaged->y;
		}
		void set(float value)
		{
			unmanaged->y = value;
		}
	}
	property float Z
	{
		float get()
		{
			return unmanaged->z;
		}
		void set(float value)
		{
			unmanaged->z = value;
		}
	}
	void Set(vec3*_unmanaged)
	{
		unmanaged = _unmanaged;
	}
	Vector3()
	{
		unmanaged = new vec3();
	}
	Vector3(vec3* _unmanaged)
	{
		unmanaged = _unmanaged;
	}
};

