#version 330 core

layout(location = 0) in vec4 position;
uniform vec2 uOffset;

void main()
{
	gl_Position = position + vec4(uOffset.xy, 0.0, 0.0);
}
