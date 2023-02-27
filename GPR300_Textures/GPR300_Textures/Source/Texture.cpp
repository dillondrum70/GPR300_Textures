#include "Texture.h"

#include "stb_image.h"

GLuint Texture::CreateTexture(const char* filePath)
{
	//Create texture name
	glGenTextures(1, &texture);

	//Make it a 2D texture
	glBindTexture(GL_TEXTURE_2D, texture);

	//Use if texture is vertically flipped
	//stbi_set_flip_vertically_on_load(true);

	//Load in our texture data from the file path
	textureData = stbi_load(filePath, &dimensions.x, &dimensions.y, &fileChannels, desiredChannels);

	//Set texture data
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, dimensions.x, dimensions.y, 0, format, type, textureData);

	//Set wrapping behavior
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, verticalWrapMode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, horizontalWrapMode);

	//Set filtering behavior
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);

	glGenerateMipmap(GL_TEXTURE_2D);

	return texture;
}