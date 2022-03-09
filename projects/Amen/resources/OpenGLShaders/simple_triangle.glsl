#shader vertex
#version 330

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;

out vec4 vertexColor;

void main()
{
	vertexColor = vec4(aColor, 1.0);
	gl_Position = vec4(aPos, 1.0);
}

#shader fragment
#version 330

in vec4 vertexColor;

out vec4 outColor;

void main()
{
	outColor = vertexColor;
}