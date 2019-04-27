#pragma once
#include <SDL_events.h>
#include <vector>
#include <functional>
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
	std::vector<std::function<void*>> observers;
	bool isRunning = true;
};