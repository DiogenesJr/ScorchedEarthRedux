#pragma once
#include <string>
#include "raylib.h"

using namespace std;

class MenuBase
{
public:
	int xPosition, yPosition, width, height;
	int xMax, yMax;
	string *menuTitle;
	Color menuColor;

	MenuBase(int xPosition, int yPosition, int width, int height, string* menuTitle, Color menuColor);
	void DrawMenu();
	void Move();
	void Redraw();
	void Click();
	void DoubleClick();
	void Hover();
};

