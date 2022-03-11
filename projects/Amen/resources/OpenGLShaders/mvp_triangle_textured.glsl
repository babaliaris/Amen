#shader vertex
#version 330

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aTexCoord;

out vec2 texCoord;

uniform mat4 u_View;
uniform mat4 u_Proj;
uniform mat4 u_Model;

void main()
{
	texCoord	= aTexCoord;
	gl_Position = u_Proj * u_View * u_Model * vec4(aPos, 1.0);
}

#shader fragment
#version 330

in vec2 texCoord;

out vec4 outColor;

void main()
{
	outColor = vec4(texCoord, 0, 1);
}