#pragma once
#include <string>
#include <SDL.h>
#include "event.h"

class Window
{
public:

	Window(const std::string _title, int _width, int _height);
	~Window();
	void PollEvents();
	bool IsClosed();
	void DrawRect(SDL_Rect _rect, uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a);
	void SetBackground(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a);
	Event* GetEvent();

private:
	bool Init();
	bool isClosed;
	int height;
	int width;
	std::string title;
	SDL_Window * window;
	SDL_Renderer * renderer;
	Event event;
};