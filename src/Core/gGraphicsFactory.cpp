#include "gGraphicsFactory.h"
namespace BAMF
{
	gMesh* gGraphicsFactory::CreateHeightMap(int width, int length, float* heightData, float horizontalScale, float verticalScale)
	{
		gMesh* mesh = new gMesh();

		mesh->vertexCount = width * length;
		mesh->vertexType = gVertexType::VertexTexture;		
		gVertexTexture* vertices = new gVertexTexture[mesh->vertexCount];

		for (int x = 0; x < width; x++)
		{
			for (int z = 0; z < length; z++)
			{
				int index = x + z * length;

				vertices[index].vertex.X = x * horizontalScale;
				vertices[index].vertex.Y = 0;
				vertices[index].vertex.Z = -z * horizontalScale;
				// color
				/*mesh->vertices[index].color.X = (float)x/10;
				mesh->vertices[index].color.Y = .5;
				mesh->vertices[index].color.Z = (float)z/10;*/
				// text coords
				vertices[index].texCoord.X = (float)x / 5;
				vertices[index].texCoord.Y = (float)z / 5;
			}
		}

		mesh->vertices = (void*)vertices;


		mesh->indexCount = (width - 1) * (length - 1) * 6;
		mesh->indices = new unsigned short[mesh->indexCount];
		int counter = 0;
		for (int y = 0; y < length - 1; y++)
		{
			for (int x = 0; x < width - 1; x++)
			{
				int lowerLeft = x + y * width;
				int lowerRight = (x + 1) + y*width;
				int topLeft = x + (y + 1) * width;
				int topRight = (x + 1) + (y + 1) * width;

				mesh->indices[counter++] = lowerLeft;
				mesh->indices[counter++] = lowerRight;
				mesh->indices[counter++] = topRight;

				mesh->indices[counter++] = topRight;
				mesh->indices[counter++] = topLeft;
				mesh->indices[counter++] = lowerLeft;
			}
		}

		mesh->texture = new gTexture();
		mesh->texture->LoadFromFile("Assets\\grass_seamless.jpg");
		return mesh;
	}

	void gGraphicsFactory::CreateBox(gMesh* mesh, int width, int height, int length, vec3 color)
	{
		int index = 0;
		int indicesIndex = 0;
		int vertexCount = 24*3;
		mesh->vertexType = gVertexType::VertexColorNormal;		
		if(mesh->vertexCount != vertexCount)
		{
			mesh->vertexCount = vertexCount;
			mesh->indexCount = 36;
			mesh->indices = new unsigned short[mesh->indexCount];

			#pragma region indices

			mesh->indices[indicesIndex++] = 0;
			mesh->indices[indicesIndex++] = 1;
			mesh->indices[indicesIndex++] = 2;

			mesh->indices[indicesIndex++] = 2;
			mesh->indices[indicesIndex++] = 3;
			mesh->indices[indicesIndex++] = 0;

			mesh->indices[indicesIndex++] = 4;
			mesh->indices[indicesIndex++] = 5;
			mesh->indices[indicesIndex++] = 6;

			mesh->indices[indicesIndex++] = 6;
			mesh->indices[indicesIndex++] = 7;
			mesh->indices[indicesIndex++] = 4;

			mesh->indices[indicesIndex++] = 8;
			mesh->indices[indicesIndex++] = 9;
			mesh->indices[indicesIndex++] = 10;

			mesh->indices[indicesIndex++] = 10;
			mesh->indices[indicesIndex++] = 11;
			mesh->indices[indicesIndex++] = 8;

			mesh->indices[indicesIndex++] = 12;
			mesh->indices[indicesIndex++] = 13;
			mesh->indices[indicesIndex++] = 14;

			mesh->indices[indicesIndex++] = 14;
			mesh->indices[indicesIndex++] = 15;
			mesh->indices[indicesIndex++] = 12;

			mesh->indices[indicesIndex++] = 16;
			mesh->indices[indicesIndex++] = 17;
			mesh->indices[indicesIndex++] = 18;

			mesh->indices[indicesIndex++] = 18;
			mesh->indices[indicesIndex++] = 19;
			mesh->indices[indicesIndex++] = 16;

			mesh->indices[indicesIndex++] = 20;
			mesh->indices[indicesIndex++] = 21;
			mesh->indices[indicesIndex++] = 22;

			mesh->indices[indicesIndex++] = 22;
			mesh->indices[indicesIndex++] = 23;
			mesh->indices[indicesIndex++] = 20;

			#pragma endregion indices
		}	

		gVertexColorNormal* vertices = new gVertexColorNormal[mesh->vertexCount];
	
		#pragma region vertices
		// front
		vertices[index].vertex.X = (float)-width / 2;
		vertices[index].vertex.Y = (float)-height / 2;
		vertices[index].vertex.Z = (float)length / 2;
		index++;

		vertices[index].vertex.X = (float)width / 2;
		vertices[index].vertex.Y = (float)-height / 2;
		vertices[index].vertex.Z = (float)length / 2;
		index++;

		vertices[index].vertex.X = (float)width / 2;
		vertices[index].vertex.Y = (float)height / 2;
		vertices[index].vertex.Z = (float)length / 2;
		index++;

		vertices[index].vertex.X = (float)-width / 2;
		vertices[index].vertex.Y = (float)height / 2;
		vertices[index].vertex.Z = (float)length / 2;
		index++;	

		// right
		vertices[index].vertex.X = (float)width / 2;
		vertices[index].vertex.Y = (float)-height / 2;
		vertices[index].vertex.Z = (float)length / 2;
		index++;

		vertices[index].vertex.X = (float)width / 2;
		vertices[index].vertex.Y = (float)-height / 2;
		vertices[index].vertex.Z = (float)-length / 2;
		index++;

		vertices[index].vertex.X = (float)width / 2;
		vertices[index].vertex.Y = (float)height / 2;
		vertices[index].vertex.Z = (float)-length / 2;
		index++;

		vertices[index].vertex.X = (float)width / 2;
		vertices[index].vertex.Y = (float)height / 2;
		vertices[index].vertex.Z = (float)length / 2;
		index++;

		// back
		vertices[index].vertex.X = (float)width / 2;
		vertices[index].vertex.Y = (float)-height / 2;
		vertices[index].vertex.Z = (float)-length / 2;
		index++;

		vertices[index].vertex.X = (float)-width / 2;
		vertices[index].vertex.Y = (float)-height / 2;
		vertices[index].vertex.Z = (float)-length / 2;
		index++;

		vertices[index].vertex.X = (float)-width / 2;
		vertices[index].vertex.Y = (float)height / 2;
		vertices[index].vertex.Z = (float)-length / 2;
		index++;

		vertices[index].vertex.X = (float)width / 2;
		vertices[index].vertex.Y = (float)height / 2;
		vertices[index].vertex.Z = (float)-length / 2;
		index++;

		// left
		vertices[index].vertex.X = (float)-width / 2;
		vertices[index].vertex.Y = (float)-height / 2;
		vertices[index].vertex.Z = (float)-length / 2;
		index++;

		vertices[index].vertex.X = (float)-width / 2;
		vertices[index].vertex.Y = (float)-height / 2;
		vertices[index].vertex.Z = (float)length / 2;
		index++;

		vertices[index].vertex.X = (float)-width / 2;
		vertices[index].vertex.Y = (float)height / 2;
		vertices[index].vertex.Z = (float)length / 2;
		index++;

		vertices[index].vertex.X = (float)-width / 2;
		vertices[index].vertex.Y = (float)height / 2;
		vertices[index].vertex.Z = (float)-length / 2;
		index++;

		// top
		vertices[index].vertex.X = (float)-width / 2;
		vertices[index].vertex.Y = (float)height / 2;
		vertices[index].vertex.Z = (float)length / 2;
		index++;

		vertices[index].vertex.X = (float)width / 2;
		vertices[index].vertex.Y = (float)height / 2;
		vertices[index].vertex.Z = (float)length / 2;
		index++;

		vertices[index].vertex.X = (float)width / 2;
		vertices[index].vertex.Y = (float)height / 2;
		vertices[index].vertex.Z = (float)-length / 2;
		index++;

		vertices[index].vertex.X = (float)-width / 2;
		vertices[index].vertex.Y = (float)height / 2;
		vertices[index].vertex.Z = (float)-length / 2;
		index++;

		// bottom
		vertices[index].vertex.X = (float)width / 2;
		vertices[index].vertex.Y = (float)-height / 2;
		vertices[index].vertex.Z = (float)-length / 2;
		index++;

		vertices[index].vertex.X = (float)-width / 2;
		vertices[index].vertex.Y = (float)-height / 2;
		vertices[index].vertex.Z = (float)-length / 2;
		index++;

		vertices[index].vertex.X = (float)-width / 2;
		vertices[index].vertex.Y = (float)-height / 2;
		vertices[index].vertex.Z = (float)length / 2;
		index++;

		vertices[index].vertex.X = (float)width / 2;
		vertices[index].vertex.Y = (float)-height / 2;
		vertices[index].vertex.Z = (float)length / 2;
		index++;
		#pragma endregion vertices

		#pragma region colors
		for(int i = 0; i < vertexCount; i++)
		{
			vertices[i].color.X = color.x;
			vertices[i].color.Y = color.y;
			vertices[i].color.Z = color.z;
		}
		#pragma endregion colors
		
		#pragma region normals
			
		for(int i = 0; i < 4; i++)
		{
			vertices[i].normal.X = 0;
			vertices[i].normal.Y = 0;
			vertices[i].normal.Z = 1;
		}
		for(int i = 4; i < 8; i++)
		{
			vertices[i].normal.X = 1;
			vertices[i].normal.Y = 0;
			vertices[i].normal.Z = 0;
		}
		for(int i = 8; i < 12; i++)
		{
			vertices[i].normal.X = 0;
			vertices[i].normal.Y = 0;
			vertices[i].normal.Z = -1;
		}
		for(int i = 12; i < 16; i++)
		{
			vertices[i].normal.X = -1;
			vertices[i].normal.Y = 0;
			vertices[i].normal.Z = 0;
		}
		for(int i = 16; i < 20; i++)
		{
			vertices[i].normal.X = 0;
			vertices[i].normal.Y = 1;
			vertices[i].normal.Z = 0;
		}
		for(int i = 20; i < 24; i++)
		{
			vertices[i].normal.X = 0;
			vertices[i].normal.Y = -1;
			vertices[i].normal.Z = 0;
		}
		#pragma endregion normals

		mesh->vertices = (void*)vertices;

	}

	gGraphicsFactory::gGraphicsFactory(void)
	{
	}


	gGraphicsFactory::~gGraphicsFactory(void)
	{
	}
}