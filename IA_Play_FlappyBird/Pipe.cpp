#include "Pipe.h"

Pipe::Pipe(sf::Vector2f currentPosition) : GameObject(currentPosition)
{
	upperPipe.setSize(sizePipe);
	upperPipe.setOutlineThickness(2);
	upperPipe.setFillColor(sf::Color::Black);
	upperPipe.setOutlineColor(sf::Color::White);
	upperPipe.setPosition(currentPosition.x, currentPosition.y);
	position = currentPosition;
	pipeSpeed = 150.f;
}

void Pipe::moveAcross(sf::Vector2f* position, float speed, float deltaTime)
{
	position->x -= speed * deltaTime;
}

void Pipe::render(sf::RenderWindow* window)
{
	window->draw(upperPipe);
}

void Pipe::update(sf::RenderWindow* window, float deltaTime)
{
	this->moveAcross(&position, pipeSpeed, deltaTime);
	upperPipe.setPosition(position);
}

sf::Vector2f Pipe::getPipeSize()
{
	return sizePipe;
}

sf::Vector2f Pipe::getPipePosition()
{
	return upperPipe.getPosition();
}

sf::FloatRect Pipe::getPipeBounds()
{
	return upperPipe.getGlobalBounds();
}

void Pipe::setPosition(sf::Vector2f pos)
{
	upperPipe.setPosition(pos);
}


Pipe::~Pipe()
{
}

float Pipe::pipeSpeed = 150.f;



