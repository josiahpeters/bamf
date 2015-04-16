#pragma once

#include "Vector3.h"

using namespace BAMF;
using namespace System::ComponentModel;

[TypeConverter(ExpandableObjectConverter::typeid)] 
ref class Cube
{
public:
	property String^ Name;

	[Category("Attributes")]
	property float Width;
	[Category("Attributes")]
	property float Height;
	[Category("Attributes")]
	property float Length;

	[Category("Orientation")]
	property Vector3^ Position;
	[Category("Orientation")]
	property Vector3^ Rotation;

	Cube()
	{
		Position = gcnew Vector3();
		Rotation = gcnew Vector3();
	}
};