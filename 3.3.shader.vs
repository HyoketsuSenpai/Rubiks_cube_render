#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

uniform mat4 v;

out vec3 ourColor;
out vec3 ourPosition;

void main()
{
    gl_Position = v * vec4(aPos, 1.0); 
    ourColor = aColor;
    ourPosition = aPos;
}