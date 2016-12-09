#version 430 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 colour;

out vec3 outColour;

void main()
{
	outColour = colour;
	gl_Position = vec4(vertex, 1.0f);
}