#include "gRenderSystem.h"

namespace BAMF
{
	void gRenderSystem::SetRendermode(RenderMode mode)
	{
		switch (mode)
		{
		case Solid:
			glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
			break;
		case Wireframe:
			glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
			break;
		}
	}

	void gRenderSystem::Render()
	{
		//glClearColor(0.39f, 0.58f, 0.92f, 0.0f);
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//glLoadIdentity();
		////gluLookAt(0,0,0, 0,0,0, 0, 1, 0);
		//glTranslatef(-1.5f,0.0f,-6.0f);
		//glBegin(GL_TRIANGLES);								// Drawing Using Triangles
		//glVertex3f( 0.0f, 1.0f, 0.0f);					// Top
		//glVertex3f(-1.0f,-1.0f, 0.0f);					// Bottom Left
		//glVertex3f( 1.0f,-1.0f, 0.0f);					// Bottom Right
		//glEnd();											// Finished Drawing The Triangle
		//glTranslatef(3.0f,0.0f,0.0f);						// Move Right 3 Units
		//glBegin(GL_QUADS);									// Draw A Quad
		//glVertex3f(-1.0f, 1.0f, 0.0f);					// Top Left
		//glVertex3f( 1.0f, 1.0f, 0.0f);					// Top Right
		//glVertex3f( 1.0f,-1.0f, 0.0f);					// Bottom Right
		//glVertex3f(-1.0f,-1.0f, 0.0f);					// Bottom Left
		//glEnd();

		glClearColor(0.39f, 0.58f, 0.92f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(12,8,-12, 5,0,-5, 0, 1, 0);

		map<gEntity*, gComponent*> cameraMapping = EntitySystem->GetEntityMapping(gCameraComponent::TypeId);
		for(map<gEntity*, gComponent*>::iterator it = cameraMapping.begin(); it != cameraMapping.end(); ++it)
		{
			gEntity* entity = it->first;

			gCameraComponent* camera = static_cast<gCameraComponent*>(it->second);
			if(camera)
			{
				glLoadIdentity();
				
				vec3 position = camera->position;
				vec3 lookat = camera->Lookat();

				mat4 lookatmat = lookAt(position, lookat, vec3(0,1,0));
				
				glLoadMatrixf(glm::value_ptr(lookatmat));

//				gluLookAt(position.x, position.y, position.z, lookat.x, lookat.y, position.z, 0, 1, 0);
			}
		}

		map<gEntity*, gComponent*> vertexMapping = EntitySystem->GetEntityMapping(gVertexComponent::TypeId);
		for(map<gEntity*, gComponent*>::iterator it = vertexMapping.begin(); it != vertexMapping.end(); ++it)
		{
			gEntity* entity = it->first;

			gVertexComponent* vert = static_cast<gVertexComponent*>(it->second);
			if(vert)
			{
				if(vert->mesh->vertexType == gVertexType::VertexTexture)
				{
					textureShader->Bind();	
					glEnable(GL_TEXTURE_2D);  

					glEnableVertexAttribArray(0);
					glEnableVertexAttribArray(1);

					glBindBuffer(GL_ARRAY_BUFFER, vert->mesh->vertexBuffer);

					glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(gVertexTexture), 0);
					glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(gVertexTexture), (const GLvoid*)12);

					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vert->mesh->indexBuffer);

					glActiveTexture(GL_TEXTURE0);
					glBindTexture(GL_TEXTURE0, vert->mesh->texture->texture);

					glDrawElements(GL_TRIANGLES, vert->mesh->indexCount, GL_UNSIGNED_SHORT, NULL);

					glDisableVertexAttribArray(0);
					glDisableVertexAttribArray(1);

					textureShader->UnBind();
				}
				else if(vert->mesh->vertexType == gVertexType::VertexColorNormal)
				{
					vertexColorNormalShader->Bind();	

					glEnableVertexAttribArray(0);
					glEnableVertexAttribArray(1);
					glEnableVertexAttribArray(2);

					glBindBuffer(GL_ARRAY_BUFFER, vert->mesh->vertexBuffer);

					glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(gVertexColorNormal), 0);
					glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(gVertexColorNormal), (const GLvoid*)12);
					glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(gVertexColorNormal), (const GLvoid*)24);

					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vert->mesh->indexBuffer);			

					glDrawElements(GL_TRIANGLES, vert->mesh->indexCount, GL_UNSIGNED_SHORT, NULL);

					glDisableVertexAttribArray(0);
					glDisableVertexAttribArray(1);
					glDisableVertexAttribArray(2);

					vertexColorNormalShader->UnBind();
				}
				else
				{
					vertexShader->Bind();	

					glEnableVertexAttribArray(0);

					glBindBuffer(GL_ARRAY_BUFFER, vert->mesh->vertexBuffer);

					glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(gVertex), 0);

					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vert->mesh->indexBuffer);			

					glDrawElements(GL_TRIANGLES, vert->mesh->indexCount, GL_UNSIGNED_SHORT, NULL);

					glDisableVertexAttribArray(0);

					vertexShader->UnBind();
				}
			}
		}
	}

	gRenderSystem::gRenderSystem(gEntitySystem* entitySystem)
	{
		EntitySystem = entitySystem;
		EntitySystem->AddSystem(this);

		glShadeModel(GL_SMOOTH);

		glEnable(GL_DEPTH_TEST);
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);		
		glEnable(GL_TEXTURE_2D); 
	}
	void gRenderSystem::LoadShader()
	{
		textureShader = new gShader();
		textureShader->Init("Assets\\Shaders\\texture.vert", "Assets\\Shaders\\texture.frag");

		vertexShader = new gShader();
		vertexShader->Init("Assets\\Shaders\\vertex.vert", "Assets\\Shaders\\vertex.frag");

		vertexColorNormalShader = new gShader();
		vertexColorNormalShader->Init("Assets\\Shaders\\vertexColorNormal.vert", "Assets\\Shaders\\vertexColorNormal.frag");
	}
	gRenderSystem::~gRenderSystem(void)
	{
	}
}
