#pragma once

#include <gl/glew.h>

#include "gMesh.h"

namespace BAMF
{
	void gMesh::CreateVBO()
	{
		if(vertexCount > 0)
		{
			glGenBuffers(1, &vertexBuffer);
			glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

			if(vertexType == gVertexType::VertexTexture)
				glBufferData(GL_ARRAY_BUFFER, sizeof(gVertexTexture) * vertexCount, vertices, GL_STATIC_DRAW);
			else
				glBufferData(GL_ARRAY_BUFFER, sizeof(gVertex) * vertexCount, vertices, GL_STATIC_DRAW);
		}
		if(indexCount > 0)
		{
			glGenBuffers(1, &indexBuffer);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned short) * indexCount, indices, GL_STATIC_DRAW);
		}
	}
	void gMesh::Draw()
	{
		if(vertexCount > 0)
		{
			
			glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			// vertex
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(gVertex), 0);
			// color 
			// glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(gVertex), (const GLvoid*)12);
			// texcoord
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(gVertex), (const GLvoid*)12);
			texture->Bind(GL_TEXTURE0);
			if(indexCount > 0)
			{
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
				glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_SHORT, NULL);
			}
			else
				glDrawArrays(GL_TRIANGLES, 0, vertexCount);
			glDisableVertexAttribArray(0);
			glDisableVertexAttribArray(1);
		}
	}
	gMesh::gMesh(void)
	{
		vertexCount = 0;
		indexCount = 0;
		indexBuffer = 0;
		vertexBuffer = 0;
		texture = NULL;
	}
	gMesh::~gMesh(void)
	{
	}
}