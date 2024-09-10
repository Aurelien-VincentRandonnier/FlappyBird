#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp> 

#include "GameObject.h"


class Player : public GameObject
{
public:
	//variable
	sf::Vector2f playerPosition;
	sf::Vector2f velocity;
	sf::CircleShape circle;
	float jumpForce = -500.f;
	bool canJump = true;
	int i = 0;

	//method
	Player(sf::Vector2f currentPosition);
	virtual void render(sf::RenderWindow* window) override;
	virtual void update(sf::RenderWindow* window, float deltaTime) override;
	virtual void jump(sf::Vector2f* pos, sf::Vector2f* velocity, float deltaTime) override;
	bool collision(sf::FloatRect pipeBonds);
	void resetPos();


};

