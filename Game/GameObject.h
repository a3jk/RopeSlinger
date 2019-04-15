#pragma once
#include "Transform.h"
#include "Sprite.h"

class GameObject
{
public:
	Transform transform;
	Sprite* sprite;
	GameObject* parent = NULL;
	void Draw();
};