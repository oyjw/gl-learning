#version 330

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;

smooth out vec4 theColor;

uniform vec3 offset;
uniform mat4 perspectiveMatrix;

void main()
{
	vec4 cameraPos = position + vec4(offset.x, offset.y, offset.z, 0.0);

	//gl_Position = perspectiveMatrix * cameraPos;
	gl_Position.xy = cameraPos.xy;
	gl_Position.z = cameraPos.z*2.0f + 3.0f;
	gl_Position.w = -cameraPos.z;

	float tmp = gl_Position.z / gl_Position.w;
	theColor = color;
	
}