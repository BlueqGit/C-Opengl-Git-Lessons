#version 460
layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 vertex_color;
layout(location = 2) in vec2 tex_cords;
out vec3 color;
out vec2 texture_cords;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

void main()
{
	gl_Position = projection * view * model * vec4(vertex_position, 1.0);

	color = vertex_color;
	texture_cords = tex_cords;
}