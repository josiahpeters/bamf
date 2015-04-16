#version 130
layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 Color;
layout (location = 2) in vec3 Normal;

out vec3 gColor;
void main() 
{            
    gl_Position = gl_ModelViewProjectionMatrix * vec4(Position, 1.0);
	gColor = Color;
}