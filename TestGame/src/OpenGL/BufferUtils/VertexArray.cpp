#include "VertexArray.h"

VertexArray::VertexArray()
{
	GLCall(glGenVertexArrays(1, &m_RendererID));
}

VertexArray::~VertexArray()
{
	for (int i = 0; i < m_Buffers.size(); i++)
	{
		delete m_Buffers[i];
	}
}

void VertexArray::AddBufffer(Buffer* buffer, unsigned int index) const
{
	Bind();
	buffer->Bind();

	GLCall(glEnableVertexAttribArray(index));
	GLCall(glVertexAttribPointer(index, buffer->GetCount(), GL_FLOAT, GL_FALSE, 0, 0));
}

void VertexArray::Bind() const
{
	GLCall(glBindVertexArray(m_RendererID));
}

void VertexArray::Unbind() const
{
	GLCall(glBindVertexArray(0));
}
