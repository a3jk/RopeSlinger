#pragma once
#include <SDL_events.h>
#include "Vector2.h"

class Event
{
public:
	Event();
	~Event();
	void PollEvent();
	int IsRunning();
	Vector2 GetMousePos();
private:
	Vector2 mouse;
	SDL_Event event;
	bool isRunning = true;
};