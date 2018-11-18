#include "window.h"
#include <iostream>



Window::Window(const std::string _title, int _width, int _height)
{
	title = _title;
	width = _width;
	height = _height;

	if (!Init())
	{
		std::cerr << "Initialization failed with SDL error code: " << SDL_Error;
	}
	else
	{
		isClosed = false;
	}
}

Window::~Window()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Window::Init()
{
	if (NULL != SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cerr << "SDL could not initialize." << SDL_Error;
		return false;
	}

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	if (NULL == window)
	{
		std::cerr << "SDL could not create the window." << SDL_Error;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (NULL == renderer)
	{
		std::cerr << "SDL could not create the renderer." << SDL_Error;
		return false;
	}

	return true;
}

void Window::PollEvent()
{
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isClosed = true;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				isClosed = true;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

bool Window::IsClosed()
{
	return isClosed;
}

void * Window::GetRenderer()
{
	return renderer;
}
