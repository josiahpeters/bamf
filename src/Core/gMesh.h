#pragma once
#include <gl/glew.h>
#include <stdlib.h>
#include "gVertex.h"
#include "gTexture.h"

namespace BAMF
{
	class gMesh
	{
	public:
		GLuint vertexBuffer;
		GLuint indexBuffer;

		void* vertices;
		int vertexCount;
		gVertexType vertexType;		

		unsigned short* indices;
		int indexCount;

		gTexture* texture;
		
		void CreateVBO();
		void Draw();

		gMesh(void);
		~gMesh(void);
	};
}

