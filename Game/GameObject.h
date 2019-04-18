#pragma once
#include "Transform.h"

class GameObject
{
public:
	Transform transform;
	GameObject* parent = NULL;
	GameObject* children = NULL;
};