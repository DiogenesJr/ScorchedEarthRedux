#include "GameEngine.h"
#include "GameObject.h"

GameEngine::GameEngine() {
	//Initialize the game objects vector
	vector<GameObject> gameObjects;
	this->gameObjects = gameObjects;

	this->defaultScreenWidth = 1024;
	this->defaultScreenHeight = 768;

	this->gameTitle = "Scorched Earth: Redux";
	this->isFullScreen = true;
	this->targetFPS = 60;
}

vector<GameObject> GameEngine::GetGameObjects() {
	return this->gameObjects;
}

void GameEngine::AddGameObject(GameObject &gameObject) {
	this->gameObjects.push_back(gameObject);
}