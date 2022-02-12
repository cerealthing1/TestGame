#include "CheckGLErrors.h"

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