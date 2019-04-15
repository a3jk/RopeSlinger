#include <iostream>
#include "Window.h"

int main(int argc, char* argv[])
{
	Window window("My Game", 500, 500);

	if (window.Init())
	{
		while (window.IsRunning())
		{
			window.Update();
		}
	}
	else
	{
		std::cerr << "Initialization failed with SDL error code: " << SDL_Error;
	}

	return 0;
}