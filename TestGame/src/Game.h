#pragma once

#include "Renderer.h"
#include "Window.h"


class Game
{
public:
	Game(const char* title, unsigned int width, unsigned int height);
	~Game();

	void Init();
	void Update();
	void Render();
	void Run();

private:
	Window* m_Window;
	Renderer m_Renderer;
};

