#include "GameObject.h"

GameObject::GameObject(sf::Vector2f position) : position(position)
{
}


void GameObject::gravity(sf::Vector2f* pos, sf::Vector2f* velocity, float dt)
{
	//Euler Method
	*velocity += gravityScale * dt;
	*pos += *velocity * dt;
}

void GameObject::bounce(sf::RenderWindow* window, sf::Vector2f* pos, sf::Vector2f* velocity, float dt)
{
	if (pos->y + 30 > window->getSize().y) {
		pos->y = window->getSize().y - 30;
		velocity->y *= -0.75;
		//Game::win = false;
	}
	//else if (pos->y - 30 < 0)
		//Game::win = false;
		
}

void GameObject::jump(sf::Vector2f* pos, sf::Vector2f* velocity, float dt)
{
	return;
}

GameObject::~GameObject()
{
}
