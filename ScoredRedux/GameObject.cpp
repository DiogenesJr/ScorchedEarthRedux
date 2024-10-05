#include "GameObject.h"

GameObject::GameObject(double xPosition, double yPosition, string* name) {
	this->xPosition = xPosition;
	this->yPosition = yPosition;
	this->name = name;
	this->hitPoints = 100.0;
	this->isAlive = true;
}