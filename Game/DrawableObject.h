#pragma once
#include "GameObject.h"
#include "Sprite.h"

class DrawableObject : GameObject
{
	Sprite* sprite;
	void Draw();
};