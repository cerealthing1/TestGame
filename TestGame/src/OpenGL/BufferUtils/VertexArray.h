#pragma once

#include <vector>
#include "Buffer.h"
#include "CheckGLErrors.h"

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void AddBufffer(Buffer* buffer, unsigned int index) const;
	void Bind() const;
	void Unbind() const;


private:
	std::vector<Buffer*> m_Buffers;
	unsigned int m_RendererID;
};
