#pragma once


namespace BAMF
{
	struct gVec4
	{
		float X;
		float Y;
		float Z;
		float W;

		gVec4(float x, float y, float z, float w)
		{
			X = x;
			Y = y;
			Z = z;
			W = w;
		}
		gVec4()
		{
			X = 0;
			Y = 0;
			Z = 0;
			W = 0;
		}
	};
	struct gVec3
	{
		float X;
		float Y;
		float Z;

		gVec3(float x, float y, float z)
		{
			X = x;
			Y = y;
			Z = z;
		}
		gVec3()
		{
			X = 0;
			Y = 0;
			Z = 0;
		}
	};
	struct gVec2
	{
		float X;
		float Y;

		gVec2(float x, float y)
		{
			X = x;
			Y = y;
		}
		gVec2()
		{
			X = 0;
			Y = 0;
		}
	};
}
