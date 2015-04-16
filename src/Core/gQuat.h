#pragma once

namespace BAMF
{
	struct gQuat
	{
		float X;
		float Y;
		float Z;
		float W;

		gQuat(float x, float y, float z, float w)
		{
			X = x;
			Y = y;
			Z = z;
			W = w;
		}
		gQuat()
		{
			X = 0;
			Y = 0;
			Z = 0;
			W = 0;
		}
	};
}
