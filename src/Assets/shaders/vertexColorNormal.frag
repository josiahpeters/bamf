#version 130
in vec3 gColor;
void main() 
{
	gl_FragColor = vec4(gColor, 1);
}