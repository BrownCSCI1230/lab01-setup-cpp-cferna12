#version 330 core
layout(location = 0) in vec3 vertex;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 texCoords;
out vec4 vert;
out vec4 norm;
out vec3 color;
out vec3 lightDir;

uniform mat4 projMatrix;
uniform mat4 mvMatrix;
uniform vec3 lightPos;

void main()
{
    vert  = vec4(vertex,1);
    norm  = vec4(normal,0);
    color = vec3(1);
    lightDir = normalize(-lightPos);
//    lightDir = normalize(vec3(mvMatrix * vec4(2, 0, 2, 0)));
    gl_Position = vert;
}
