#pragma once

#include <iostream>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <stdlib.h>
#include <windows.h>
#include <gl/glew.h>
#include <gl/gl.h>
//#include <gl/glu.h>
#include <IL/il.h>

#include <stdio.h>
#include <direct.h>

using namespace std;

namespace BAMF
{
	class gShader
	{
		GLint vshader;
		GLint fshader;
		GLint shaderId;

		const GLchar* vertexString;
		const GLchar* fragmentString;

	public:

		GLint gSampler;

		void Bind()
		{
			glUseProgram(shaderId);
		}
		void UnBind()
		{
			glUseProgram(0);
		}
		void BindTextureIndex(int index)
		{
			glUniform1i(gSampler, index);
		}
		gShader() 
		{
		}
		void Init(char* vertexFile, char* fragmentFile)
		{
			vertexString = read_file(vertexFile);
			fragmentString = read_file(fragmentFile);

			vshader = glCreateShader(GL_VERTEX_SHADER);
			fshader = glCreateShader(GL_FRAGMENT_SHADER);

			
			glShaderSource(vshader, 1, &vertexString, 0);
			glShaderSource(fshader, 1, &fragmentString, 0);

			glCompileShader(vshader);
			validateShader(vshader,vertexFile);

			glCompileShader(fshader);
			validateShader(fshader,fragmentString);

			shaderId = glCreateProgram();
			glAttachShader(shaderId, vshader);
			glAttachShader(shaderId, fshader);
			glLinkProgram(shaderId);

			glValidateProgram(shaderId);
			GLint status;

			string str;

			glGetProgramiv(shaderId, GL_VALIDATE_STATUS, &status);
			if (status == GL_FALSE)
				str = "ruh roh";

			glUseProgram(shaderId);
			gSampler = glGetUniformLocation(shaderId, "gSampler");

			glUniform1i(gSampler, 0);
		}
		static void validateShader(GLuint shader, const char* file = 0) 
		{
			const unsigned int BUFFER_SIZE = 512;
			char buffer[BUFFER_SIZE];
			memset(buffer, 0, BUFFER_SIZE);
			GLsizei length = 0;

			glGetShaderInfoLog(shader, BUFFER_SIZE, &length, buffer);
			if (length > 0) {
				cerr << "Shader " << shader << " (" << (file?file:"") << ") compile error: " << buffer << endl;
			}
		}
		static const char* read_file(char* filename)
		{
			FILE *fd;
			long len, r;
			char *str;

			if (!(fd = fopen(filename, "r")))
				return NULL;

			fseek(fd, 0, SEEK_END);
			len = ftell(fd);
			fseek(fd, 0, SEEK_SET);
			str = new char[len+1];
			r = fread(str, sizeof(char), len, fd);
			str[r] = '\0';
			fclose(fd);

			return str;
			/*
		
			ifstream file (filename);	
			if(file.good())
			{
				stringstream buffer;
				buffer << file.rdbuf();
				file.close();
				string test  = buffer.str();
				const char* c = test.c_str();
				return c;
			}
			else
				return "";*/
		}
	};
}