#pragma once
#include "raylib.hpp"

class App
{
private:
	int _width, _heigth;
public:
	App();
	App(const char* name, int width, int height);
	~App();

	void update();
};