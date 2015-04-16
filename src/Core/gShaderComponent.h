#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <windows.h>
#include <gl/glew.h>
#include <gl/gl.h>
//#include <gl/glu.h>
#include <IL/il.h>


#include "gComponent.h"
#include "gVector.h"

using namespace std;

namespace BAMF
{
	class gShaderComponent : public gComponent
	{
	public:
		static const gComponentTypeId TypeId = 2;

		GLuint vertex_buffer;
		GLuint element_buffer;
		GLuint textures[2];

		GLuint program;
		GLuint vertex_shader;
		GLuint fragment_shader;
		GLint position;
		GLint fade_factor;
		GLint stextures[2];

		gShaderComponent()
		{
			static const GLfloat g_vertex_buffer_data[] = 
			{ 
				0, 0, 0,
				5, 0, 0,
				2.5f, 5, 0
			};
			static const GLushort g_element_buffer_data[] = { 0, 1, 2 };

			vertex_buffer = 0;
			element_buffer = 0;
			program = 0;
			vertex_shader = 0;
			fragment_shader = 0;

			glClearColor(0.39f, 0.58f, 0.92f, 0.0f);

			GLuint* test = new GLuint();

			glGenBuffers(1, test);
			glBindBuffer(GL_ARRAY_BUFFER, *test);
			glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data)*3, g_vertex_buffer_data, GL_STATIC_DRAW);

			glGenBuffers(1, &element_buffer);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(g_element_buffer_data)*3, g_element_buffer_data, GL_STATIC_DRAW);

			/*ilGenImages(1, &textures[0]);
			ilBindImage(textures[0]);
			ilLoadImage((const ILstring) "Assets\\gl2-hello-1.png");

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_CLAMP_TO_EDGE);

			ilGenImages(1, &textures[1]);
			ilBindImage(textures[1]);
			ilLoadImage((const ILstring) "Assets\\gl2-hello-1.png");

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_CLAMP_TO_EDGE);*/

			GLint length;
			GLchar *source = read_file("Assets\\hello.v.glsl", &length);

			vertex_shader = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertex_shader, 1, (const GLchar**)&source, &length);
			glCompileShader(vertex_shader);
			//free(source);

			source = read_file("Assets\\hello.f.glsl", &length);

			fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragment_shader, 1, (const GLchar**)&source, &length);
			glCompileShader(fragment_shader);
			//free(source);

			program = glCreateProgram();
			glAttachShader(program, vertex_shader);
			glAttachShader(program, fragment_shader);
			glLinkProgram(program);

			position = glGetUniformLocation(program, "position");
			/*fade_factor = glGetUniformLocation(program, "fade_factor");
			stextures[0] = glGetUniformLocation(program, "textures[0]");
			stextures[0] = glGetUniformLocation(program, "textures[1]");*/
		}
		static GLchar * read_file(char* filename, int* length)
		{
			ifstream file (filename);	
			stringstream buffer;
			*length = (int)file.tellg();
			buffer << file.rdbuf();
			file.close();
			return (GLchar*)buffer.str().c_str();
		}
		~gShaderComponent(void);
	};
}

