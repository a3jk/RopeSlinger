#include "event.h"

Event::Event()
{

}

Event::~Event()
{

}

int Event::PollEvent()
{
	int value = 0;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			value = SDL_QUIT;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT:
				break;
			case SDLK_RIGHT:
				break;
			case SDLK_DOWN:
				break;
			case SDLK_UP:
				break;
			case SDLK_ESCAPE:
				isClosed = true;
				break;
			default:
				break;
			}
			break;
		case SDL_MOUSEMOTION:
			mouse.x = event.motion.x;
			mouse.y = event.motion.y;
			break;
		default:
			break;
		}
	}
	return value;
}

MouseData Event::GetMousePos()
{
	return mouse;
}

int Event::IsClosed()
{
	return isClosed;
}
