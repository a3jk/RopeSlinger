#include <iostream>
#include "Window.h"

int main(int argc, char* argv[])
{
	Window window("mitt spel", 500, 500);

	while (!window.IsClosed())
	{
		window.PollEvents();
	}
	return 0;
}