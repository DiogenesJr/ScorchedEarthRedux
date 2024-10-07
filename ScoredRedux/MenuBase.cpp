#include "MenuBase.h"
#include "raylib.h"

MenuBase::MenuBase(int xPosition, int yPosition, int width, int height, string* menuTitle, Color menuColor) {
	this->xPosition = xPosition;
	this->yPosition = yPosition;
	this->xMax = xPosition + width;
	this->yMax = yPosition + height;
	this->width = width;
	this->height = height;
	this->menuTitle = menuTitle;
	this->menuColor = menuColor;

}

void MenuBase::Move() {}
void MenuBase::Redraw() {}
void MenuBase::Click() {
	Vector2 mousePosition = GetMousePosition();
	if ((mousePosition.x >= this->xMax) && (mousePosition.x <= this->xPosition)) {
		if ((mousePosition.y >= this->yMax) && (mousePosition.y <= this->yPosition)) {

		}
	}
}
void MenuBase::DoubleClick() {}
void MenuBase::Hover() {}

void MenuBase::DrawMenu() {
	//Draw the entire menu background
	DrawRectangle(this->xPosition, this->yPosition, this->width, this->height, this->menuColor);
	DrawRectangle(this->xPosition, this->yPosition, this->width, 30, this->menuColor);
	//TODO:Draw Menu Controls
	DrawText(this->menuTitle->data(), this->xPosition, this->yPosition, 10, BLACK);

}
