#version 130
layout (location = 0) in vec3 Position;
void main() 
{            
    gl_Position = gl_ModelViewProjectionMatrix * vec4(Position, 1.0);
}