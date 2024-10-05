#pragma once
#include <vector>
#include "GameObject.h"
using namespace std;

class GameEngine
{
	vector<GameObject> gameObjects;
public:
	string gameTitle;
	
	int defaultScreenWidth, defaultScreenHeight, targetFPS;
	bool isFullScreen;
	
	GameEngine();

	vector<GameObject> GetGameObjects();
	void AddGameObject(GameObject &gameObject);
};

