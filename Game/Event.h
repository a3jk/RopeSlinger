#pragma once
#include <SDL_events.h>
#include "GameUtilities.h"

class Event
{
public:
	Event();
	~Event();
	void PollEvent();
	int IsClosed();
	Vector2 GetMousePos();
private:
	Vector2 mouse;
	SDL_Event event;
	bool isClosed = false;
};