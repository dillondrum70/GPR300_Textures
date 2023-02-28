#include "TextureManager.h"

TextureManager::TextureManager()
{
	for (int i = 0; i < MAX_TEXTURES; i++)
	{
		textures[i] = Texture(GL_TEXTURE0 + i);
	}
}

Texture TextureManager::AddTexture(const char* filePath)
{
	textures[textureCount] = Texture(GL_TEXTURE0 + textureCount);
	textures[textureCount].CreateTexture(filePath);
	glActiveTexture(textures[textureCount].texNumber);
	glBindTexture(GL_TEXTURE_2D, textures[textureCount].GetTexture());

	textureCount++;

	return textures[textureCount - 1];
}