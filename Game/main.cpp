#include <iostream>
#include "window.h"

int main(int argc, char* argv[])
{
	Window window("mitt spel", 500, 500);
	SDL_Renderer * r = (SDL_Renderer *)window.GetRenderer();

	while (!window.IsClosed())
	{
		window.PollEvent();
	}
	return 0;
}