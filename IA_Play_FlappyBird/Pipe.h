#pragma once
#include <iostream>
#include "GameObject.h"

class Pipe : public GameObject
{
public:
	static float pipeSpeed;
	sf::Vector2f pipePosition;
	sf::RectangleShape upperPipe;
	sf::Vector2f sizePipe{ 150,900 };
	Pipe(sf::Vector2f currentPosition);
	bool hadPassed = false;


	void moveAcross(sf::Vector2f* pipePosition, float speed, float deltaTime);
	virtual void render(sf::RenderWindow* window) override;
	virtual void update(sf::RenderWindow* window, float deltaTime) override;
	sf::Vector2f getPipeSize();
	sf::Vector2f getPipePosition();
	sf::FloatRect getPipeBounds();
	void setPosition(sf::Vector2f pos);
	~Pipe();

private:

};

