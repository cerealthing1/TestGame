#pragma once
#include "CheckGLErrors.h"

class Buffer
{
public:
	Buffer(float* data, unsigned int count, unsigned int compCount) : m_CompCount(compCount)
	{
		GLCall(glGenBuffers(1, &m_RendererID));
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
		GLCall(glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, GL_STATIC_DRAW));
	}

	void Bind() { GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID)); }
	void Unbind() { GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0)); }

	unsigned int GetCount() { return m_CompCount; }

private:
	unsigned int m_RendererID;
	unsigned int m_CompCount;
};