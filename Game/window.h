#pragma once
#include <string>
#include <SDL.h>

class Window
{
public:

	Window(const std::string _title, int _width, int _height);
	~Window();
	void PollEvent();
	bool IsClosed();
	void * GetRenderer();

private:
	bool Init();
	bool isClosed;
	int height;
	int width;
	std::string title;
	SDL_Window * window;
	SDL_Renderer * renderer;
	SDL_Event event;

};