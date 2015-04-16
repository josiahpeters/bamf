#pragma once

#include <glm/glm.hpp>

#include "gMesh.h"

using namespace glm;

namespace BAMF
{
	class gGraphicsFactory
	{
	public:
		static gMesh* CreateHeightMap(int width, int length, float* heightData, float horizontalScale, float verticalScale);
		static void gGraphicsFactory::CreateBox(gMesh* mesh, int width, int height, int length, vec3 color);
		gGraphicsFactory(void);
		~gGraphicsFactory(void);
	};
}
