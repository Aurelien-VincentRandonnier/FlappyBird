#include "Player.h"

Player::Player(sf::Vector2f currentPosition) : GameObject(currentPosition)
{
	playerPosition = currentPosition;

	circle.setRadius(30);
	circle.setOutlineColor(sf::Color::White);
	circle.setOutlineThickness(2);
	circle.setFillColor(sf::Color(0, 0, 0, 0));
	circle.setPosition(currentPosition);
}

void Player::render(sf::RenderWindow* window)
{
	window->draw(circle);
}

void Player::update(sf::RenderWindow* window, float deltaTime)
{
	//bounce methode in GO
	bounce(window, &playerPosition, &velocity, deltaTime);


	//input related to jump

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if (canJump) {
			//std::cout << "in if jump" << "\n";
			jump(&playerPosition, &velocity, deltaTime);
			canJump = false;
		}
	}
	else {
		canJump = true;
	}

	//gravity method set in GO
	gravity(&playerPosition, &velocity, deltaTime);


	//draw circl
	circle.setPosition(playerPosition);

}

void Player::jump(sf::Vector2f* pos, sf::Vector2f* velocity, float deltaTime)
{
	velocity->x = 0;
	velocity->y = 0;
	velocity->y += jumpForce;
}

bool Player::collision(sf::FloatRect pipeBonds)
{
	sf::FloatRect collision = circle.getGlobalBounds();
	if (collision.intersects(pipeBonds)) {
		return true;
	}
	return false;

}

void Player::resetPos()
{
	playerPosition.y = 700;
}


