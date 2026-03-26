#include "Texture.h"

namespace TextureS
{
	Texture::Texture(const char* path, int width, int height, int nrChannels)
	{
		this->texture = 0;
		this->data = nullptr;
		this->path = path;
		this->width = width;
		this->height = height;
		this->nrChannels = nrChannels;

		glGenTextures(1, &this->texture);
		glBindTexture(GL_TEXTURE_2D ,this->texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_set_flip_vertically_on_load(true);
		this->data = stbi_load(this->path, &this->width, &this->height, &this->nrChannels, 0);

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_RGB, GL_UNSIGNED_BYTE, this->data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Texture loading faild" << std::endl;
		}

		stbi_image_free(this->data);
	}

	unsigned int Texture::GetTextureID()
	{
		return this->texture;
	}
	Texture::~Texture()
	{
		glDeleteTextures(1, &this->texture);
	}
}