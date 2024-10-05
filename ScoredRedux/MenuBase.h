#pragma once
#include "raylib.h"

class MenuBase
{
public:
	MenuBase();
	void DrawMenu(int xPosition, int yPosition, int width, int height, const char* menuText);
};

