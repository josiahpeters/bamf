#pragma once
#include <gl/glew.h>
#include <IL/ilut.h>
#include "SOIL.h"

using namespace std;

namespace BAMF
{
	class gTexture
	{
	public:
		GLuint texture;
		void LoadFromFile(char * filename);
		void SetParameters();
		void Bind(GLenum TextureUnit);
		void UnBind();
		gTexture(void);
		~gTexture(void);
	};
}

