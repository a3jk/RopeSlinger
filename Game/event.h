#pragma once
#include <SDL.h>

struct MouseData
{
	int x;
	int y;
};

class Event
{
public:
	Event();
	~Event();
	int PollEvent();
	int IsClosed();
	MouseData GetMousePos();
private:
	MouseData mouse;
	SDL_Event event;
	bool isClosed = false;
};