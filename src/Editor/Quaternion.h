#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

using namespace glm;
using namespace BAMF;
using namespace System::ComponentModel;

[TypeConverter(ExpandableObjectConverter::typeid)] 
ref class Quaternion
{

public:
	quat* unmanaged;
	property float W
	{
		float get()
		{
			return unmanaged->w;
		}
		void set(float value)
		{
			unmanaged->w = value;
		}
	}
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

	Quaternion()
	{
		unmanaged = new quat();
	}
	Quaternion(quat* _unmanaged)
	{
		unmanaged = _unmanaged;
	}
};

