#pragma once
#include "glm/glm.hpp"

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
class Entity2D
{
protected:
	glm::vec3 m_Pos;
	glm::vec2 m_Size;
	glm::vec4 m_Color;

	Shader& m_Shader;
	VertexArray* m_VA;
	IndexBuffer* m_IB;
public:


	Entity2D(glm::vec3 pos, glm::vec2 size, glm::vec4 color, Shader& shader)
		: m_Pos(pos), m_Size(size), m_Color(color), m_Shader(shader)
	{

		unsigned int indices[] =
		{
			0, 1, 2, 2, 3, 0
		};
		float verts[] =
		{
			0,     0,       0,
			0,     size.y,  0,
			size.x, size.y, 0,
			size.x, 0,	    0
		};
		float colors[] =
		{
			color.x, color.y, color.z, color.w,
			color.x, color.y, color.z, color.w,
			color.x, color.y, color.z, color.w,
			color.x, color.y, color.z, color.w
		};


		m_VA = new VertexArray();
		m_IB = new IndexBuffer(indices, 6);

		m_VA->AddBufffer(new Buffer(verts, 4 * 3, 3), 0);
		m_VA->AddBufffer(new Buffer(colors, 4 * 4, 4), 1);
	}

	~Entity2D()
	{
		delete m_VA;
		delete m_IB;
	}

	const VertexArray* GetVA() const { return m_VA; }
	const IndexBuffer* GetIB() const { return m_IB; }
	Shader& GetShader() const { return m_Shader; }



	const glm::vec3 GetPos() const { return m_Pos; }
	const glm::vec2 GetSize() const { return m_Size; }
};

