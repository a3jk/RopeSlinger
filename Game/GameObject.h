#pragma once
#include "Transform.h"
#include <SDL.h>

class GameObject
{
	Transform transform;
	SDL_Texture* texture;
	GameObject* parent = NULL;
};