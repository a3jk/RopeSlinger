#include "Window.h"
#include <iostream>
#include <functional>

Window::Window(const std::string _title, int _width, int _height)
{
	title = _title;
	width = _width;
	height = _height;

	if (!Init())
	{
		std::cerr << "Initialization failed with SDL error code: " << SDL_Error;
		isClosed = true;
	}
	else
	{
		isClosed = false;
		SetBackground(0, 0, 25, 255);
		SDL_Rect rect
		{
			rect.x = 150,
			rect.y = 150,
			rect.h = 150,
			rect.w = 150
		};
		DrawRect(rect, 255, 0, 0, 255);
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

void Window::PollEvents()
{
	event.PollEvent();
	isClosed = event.IsClosed();
}

bool Window::IsClosed()
{
	return isClosed;
}

void Window::DrawRect(SDL_Rect _rect, uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a)
{
	SDL_SetRenderDrawColor(renderer, _r, _g, _b, _a);
	SDL_RenderFillRect(renderer, &_rect);
	SDL_RenderPresent(renderer);
}

void Window::SetBackground(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a)
{
	SDL_SetRenderDrawColor(renderer, _r, _g, _b, _a);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

Event * Window::GetEvent()
{
	return &event;
}

