#pragma once
class State
{
public:
	virtual void Update();
	State* nextState;
};