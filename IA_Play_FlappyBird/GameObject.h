#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp> 


class GameObject
{
protected:
	//variable
	sf::Vector2f position;
	sf::Vector2f gravityScale{ 0, 650 };

	//method
public:
	//variable 

	//method
	GameObject(sf::Vector2f position);
	virtual void render(sf::RenderWindow* window) = 0;
	virtual void update(sf::RenderWindow* window, float deltaTime) = 0;
	virtual void gravity(sf::Vector2f* pos, sf::Vector2f* velocity, float dt);
	virtual void bounce(sf::RenderWindow* window, sf::Vector2f* pos, sf::Vector2f* velocity, float dt);
	virtual void jump(sf::Vector2f* pos, sf::Vector2f* velocity, float dt);

	virtual ~GameObject();
};

