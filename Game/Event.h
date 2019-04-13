#pragma once
#include <SDL_events.h>


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
	void PollEvent();
	int IsClosed();
	MouseData GetMousePos();
private:
	MouseData mouse;
	SDL_Event event;
	bool isClosed = false;
};