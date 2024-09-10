#pragma once

#include "GameObject.h"
#include "Player.h"
#include "Pipe.h"


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp> 
#include <windows.h>
#include <iostream>
#include <vector>


class Game
{
private:
	#pragma region SFML Variable

	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videoMode;
	sf::Clock clock;
	sf::Font arialFont;
	sf::Text textCollisionOutputUP;
	sf::Text textCollisionOutputLP;
	sf::Clock clockPipeFrenquecy;
#pragma endregion

	#pragma region Private Variable
	float deltaTime;
	float score = 0;
	float spacing = 350;
	float windowWidth;

#pragma endregion

	#pragma region StorageArray

	std::vector<GameObject*> gameObjectArray;
	std::vector<Pipe*> pipeArray;

#pragma endregion

	Player* player;

	#pragma region Methode
	void addGameObject(GameObject* gameObject);
	void addPlayer();
	void genreateLevel();
	void playerCollisionPipe(Pipe* pipe);
	void initWindow();
	void updateAll();
	void addScore(Pipe* pipe);
	void resetGame();
	float getDeltaTime();
#pragma endregion


public:
	#pragma region Contructor Destructor
	//constructor & destructor
	Game();
	~Game();
#pragma endregion

	void run();


};