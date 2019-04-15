#pragma once
#include <string>
#include <SDL.h>
#include "Event.h"

class Window
{
public:
	Window(const std::string _title, int _width, int _height);
	~Window();
	bool Init();
	void Update();
	bool IsRunning();
	void DrawRect(SDL_Rect _rect, uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a);
	void SetBackground(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a);
	Event* GetEvent();
	SDL_Renderer* GetRenderer();
private:
	bool isRunning;
	int height;
	int width;
	std::string title;
	SDL_Renderer* renderer;
	SDL_Window* window;
	Event event;
};