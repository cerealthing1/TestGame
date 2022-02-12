#include <iostream>

#include "Window.h"
#include "Game.h"

int main(void)
{
	//Window window("TestGame", 800, 600);
	//glClearColor(0.0f, 0.4f, 0.2f, 1.0f);

	Game game("TestGame", 800, 800);
	game.Run();
	
	return 0;
}