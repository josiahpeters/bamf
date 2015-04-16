#pragma once

#include "gVector.h"

namespace BAMF
{
	enum gVertexType
	{
		Vertex,
		VertexTexture,
		VertexColorNormal,
		VertexColor
	};
	struct gVertex
	{
		gVec3 vertex;
		//gVec3 normal;
		//gVec3 color;
		//gVec2 texCoord;
	};
	struct gVertexTexture
	{
		gVec3 vertex;
		//gVec3 normal;
		//gVec3 color;
		gVec2 texCoord;
	};

	struct gVertexColorNormal
	{
		gVec3 vertex;
		gVec3 color;
		gVec3 normal;
		//gVec2 texCoord;
	};
	
	struct gVertexColor
	{
		gVec3 vertex;
		//gVec3 normal;
		gVec3 color;
		//gVec2 texCoord;
	};
}
