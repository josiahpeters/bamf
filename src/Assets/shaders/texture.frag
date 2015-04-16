#version 130
//in vec4 gColor;
in vec2 TexCoord0;
uniform sampler2D gSampler;
void main() 
{
    //gl_FragColor = gColor;
	gl_FragColor = texture2D(gSampler, TexCoord0.xy);
}