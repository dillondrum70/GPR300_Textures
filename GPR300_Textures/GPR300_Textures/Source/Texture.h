#ifndef TEXTURE_H
#define TEXTURE_H

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"

#include "imgui.h"

class Texture
{
private:
	GLuint texture = 0;

	glm::ivec2 dimensions = glm::ivec2(0);

	int fileChannels = 0;
	int desiredChannels = 0;

	GLenum format = GL_RGB;
	GLenum type = GL_UNSIGNED_BYTE;

	const char* wrapModes[4] = { "GL_REPEAT", "GL_MIRRORED_REPEAT", "GL_CLAMP_TO_EDGE", "GL_CLAMP_TO_BORDER" };
	GLint wrapEnumModes[4] = { GL_REPEAT, GL_MIRRORED_REPEAT, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER };
	int currentVertWrap = 0;
	GLint verticalWrapMode = GL_REPEAT;
	int currentHorizWrap = 0;
	GLint horizontalWrapMode = GL_REPEAT;

	//GL_LINEAR for smoother interpilation, GL_NEAREST for pixelation
	const char* filterModes[2] = { "GL_LINEAR", "GL_NEAREST" };
	GLint filterEnumModes[2] = { GL_LINEAR, GL_NEAREST };
	int currentMagFilter = 0;
	GLint magFilter = GL_LINEAR;
	int currentMinFilter = 0;
	GLint minFilter = GL_LINEAR;

	unsigned char* textureData = nullptr;

public:
	GLenum texNumber = GL_TEXTURE0;

	float scaleFactor = 1;

	Texture(GLenum textureNumber) : texNumber(textureNumber) {}

	glm::ivec2 GetDimensions() { return dimensions; }
	GLuint GetTexture() { return texture; }

	GLuint CreateTexture(const char* filePath);

	void ExposeImGui();
};

#endif