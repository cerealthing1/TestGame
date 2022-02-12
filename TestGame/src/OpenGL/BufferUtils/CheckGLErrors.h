#pragma once
#include <iostream>
#include "glad/glad.h"

// Break point macro.
#define ASSERT(x) if(!(x)) __debugbreak();

// Error checking macro.
#define GLCall(x) GLClearError(); x; ASSERT(GLLogCall(#x, __FILE__, __LINE__))

// Clear old errors
void GLClearError();

// Log error to console.
bool GLLogCall(const char* function, const char* file, int line);