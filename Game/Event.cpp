#include "Event.h"

Event::Event()
{

}

Event::~Event()
{

}

void Event::PollEvent()
{
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isClosed = true;
			break;
		case SDL_KEYDOWN:
			break;
		case SDL_MOUSEMOTION:
			mouse.x = event.motion.x;
			mouse.y = event.motion.y;
			break;
		default:
			break;
		}
	}
}

Vector2 Event::GetMousePos()
{
	return mouse;
}

int Event::IsClosed()
{
	return isClosed;
}
