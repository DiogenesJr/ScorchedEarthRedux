#include "GameEngine.h"
#include "GameObject.h"

GameEngine::GameEngine() {
	//Initialize the game objects vector
	vector<GameObject> gameObjects;
	this->gameObjects = gameObjects;

	this->defaultScreenWidth = 800;
	this->defaultScreenHeight = 450;

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