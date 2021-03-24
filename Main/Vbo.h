#pragma once

#include <glad/glad.h>
#include <cstdint>

class Vbo
{
public:
	static void build(GLuint vbo, GLfloat* vertices, uint32_t verticesLength, uint8_t* dataStep, uint32_t stepGroupLength);
};

