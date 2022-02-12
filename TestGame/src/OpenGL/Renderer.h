#pragma once

#include "glad/glad.h"

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Entity2D.h"
#include "Shader.h"

#include <deque>

/*
// Break point macro.
#define ASSERT(x) if(!(x)) __debugbreak();

// Error checking macro.
#define GLCall(x) GLClearError(); x; ASSERT(GLLogCall(#x, __FILE__, __LINE__))

// Clear old errors
void GLClearError();

// Log error to console.
bool GLLogCall(const char* function, const char* file, int line);
*/

class Renderer
{
public:
    void Clear() const;
    //void Draw(VertexArray& va, IndexBuffer& ib, Shader& shader) const;

    void Submit2D(Entity2D* renderable);
    void Flush2D();

private:
    std::deque<const Entity2D*> m_RenderQueue;
};