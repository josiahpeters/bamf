#pragma once

#include <windows.h>
#include <gl/glew.h>
#include <gl/gl.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//#include <gl/glu.h>
#include "gSystem.h"
#include "gShader.h"
#include "gEntitySystem.h"

namespace BAMF
{
	enum RenderMode
	{
		Solid,
		Wireframe
	};

	class gRenderSystem : public gSystem
	{
		gEntitySystem* EntitySystem;

		gShader* textureShader;
		gShader* vertexShader;
		gShader* vertexColorNormalShader;
		
		void Render();
	public:
		void SetRendermode(RenderMode mode);
		void LoadShader();
		virtual void Update(float duration)
		{
			Render();
		}
		gRenderSystem(gEntitySystem* entitySystem);
		~gRenderSystem(void);
	};
}

