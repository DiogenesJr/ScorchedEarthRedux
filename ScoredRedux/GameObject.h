#pragma once
#include <string>
using namespace std;

class GameObject
{
public:
	double xPosition, yPosition, hitPoints;
	bool isAlive;
	string* name;

	GameObject(double xPosition, double yPosition, string* name);	
};

