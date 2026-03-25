#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "stb_image.h"

namespace TextureS
{
	class Texture
	{
		unsigned int texture;
		unsigned char* data;
		const char* path;
		int width;
		int height;
		int nrChannels;
	public:
		Texture(const char* path, int width, int height, int nrChannels);
		Texture(const Texture&) = delete;
		unsigned int GetTextureID();
	};
}