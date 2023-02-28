#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "Texture.h"

const int MAX_TEXTURES = 32;

class TextureManager
{
public:
	Texture textures[MAX_TEXTURES];
	int textureCount = 0;

	TextureManager();

	Texture AddTexture(const char* filePath);
};

#endif