#ifndef TEXTURE_H
#define TEXTURE_H

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"

class Texture
{
private:
	GLuint texture = 0;

	glm::ivec2 dimensions = glm::ivec2(0);

	int fileChannels = 0;
	int desiredChannels = 0;

	GLenum format = GL_RGB;
	GLenum type = GL_UNSIGNED_BYTE;

	GLint verticalWrapMode = GL_REPEAT;
	GLint horizontalWrapMode = GL_REPEAT;

	//GL_LINEAR for smoother interpilation, GL_NEAREST for pixelation
	GLint magFilter = GL_LINEAR;
	GLint minFilter = GL_LINEAR;

	unsigned char* textureData = nullptr;

public:
	glm::ivec2 GetDimensions() { return dimensions; }
	GLuint GetTexture() { return texture; }

	GLuint CreateTexture(const char* filePath);
};

#endif