#include "Vbo.h"

void Vbo::build(GLuint vbo, GLfloat* vertices, uint32_t verticesLength, uint8_t* dataStep, uint32_t stepGroupLength)
{
	int floatSize = sizeof(GLfloat);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, verticesLength * floatSize, vertices, GL_STATIC_DRAW);

	//计算有效数据长度
	int stepLength = 0;
	for (int i = 0; i < stepGroupLength; i++) {
		stepLength += dataStep[i];
	}
	stepLength *= floatSize;
	//设置数据解析方式
	int offset = 0;
	for (int i = 0; i < stepGroupLength; i++) {
		glVertexAttribPointer(i, dataStep[i], GL_FLOAT, GL_FALSE, stepLength, (void*)(offset));
		glEnableVertexAttribArray(i);
		offset = offset + dataStep[i] * floatSize;
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
