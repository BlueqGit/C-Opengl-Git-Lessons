#version 460
in vec3 color;
in vec2 texture_cords;

out vec4 fragment_color;

uniform sampler2D ourTexture;

void main() 
{
	vec2 FLLIPED_texture_cords = vec2(1.0 - texture_cords.x, texture_cords.y);
	fragment_color = texture(ourTexture, FLLIPED_texture_cords);
}