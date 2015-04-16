#pragma once

#include <gl/glew.h>
#include <gl/gl.h>


#include "gComponent.h"
#include "gVector.h"
#include "gGraphicsFactory.h"

namespace BAMF
{
	

	class gVertexComponent : public gComponent
	{
	public:
		static const gComponentTypeId TypeId = 1;
		
		gMesh* mesh;

		gVertexComponent()
		{
			
		}
		~gVertexComponent(void);
	};
}

