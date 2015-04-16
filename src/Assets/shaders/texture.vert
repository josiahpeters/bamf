#version 130
layout (location = 0) in vec3 Position;
layout (location = 1) in vec2 TexCoord;
//layout (location = 1) in vec3 Color;
//out vec4 gColor;
out vec2 TexCoord0;
void main() 
{            
    gl_Position = gl_ModelViewProjectionMatrix * vec4(Position, 1.0);
	TexCoord0 = TexCoord;
}