#pragma once

#include "MenuBase.h"

class MainMenu:MenuBase{
public:
	MainMenu(int xPosition, int yPosition, int width, int height, string* menuTitle, Color menuColor) :
		MenuBase(xPosition, yPosition, width, height, menuTitle, menuColor) {}

	
};

