#include "Renderer.h"

#include<iostream>
#include "glm/gtc/matrix_transform.hpp"
/*
// Clear old errors
void GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

// Log error to console.
bool GLLogCall(const char* function, const char* file, int line) {
    while (GLenum error = glGetError()) {
        std::cout << "[OpenGL Error] (" << error << "): " << std::endl;
        std::cout << "  function: " << function << "\n";
        std::cout << "  file: " << file << "\n";
        std::cout << "  line: " << line << "\n";
        return false;
    }
    return true;
}
*/
void Renderer::Clear() const
{
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}


/*
void Renderer::Draw(VertexArray& va, IndexBuffer& ib, Shader& shader) const
{
    shader.Bind();
    va.Bind();
    ib.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}
*/

void Renderer::Submit2D(Entity2D* renderable)
{
    m_RenderQueue.push_back(renderable);
}

void Renderer::Flush2D()
{
    while (!m_RenderQueue.empty())
    {
        const Entity2D* renderable = m_RenderQueue.front();
        renderable->GetVA()->Bind();
        renderable->GetIB()->Bind();
        renderable->GetShader().Bind();

        

        renderable->GetShader().SetUniformMat4f("vw_matrix", glm::translate(glm::mat4(1.0f), glm::vec3(renderable->GetPos())));
        GLCall(glDrawElements(GL_TRIANGLES, renderable->GetIB()->GetCount(), GL_UNSIGNED_INT, nullptr));

        m_RenderQueue.pop_front();

    }
}
