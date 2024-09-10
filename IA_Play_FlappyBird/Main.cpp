#include <iostream>
#include "Game.h"
#include "Player.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp> 


int main(void) {
	system("cls");
	Game game;
	game.run();
	return 0;
}




























//class Player {
//public:
//	sf::Sprite birdSprite;
//	sf::Texture birdTexture;
//	sf::Vector2f birdScale{ 4, 4 };
//
//	Player() {
//		Player::setTexture();
//	}
//
//	void scale(float xScale, float yScale) {
//		//birdSprite.setTexture(birdTexture);
//		birdSprite.scale(xScale, yScale);
//	}
//
//	int setTexture() {
//		if (!birdTexture.loadFromFile("Assets/yellowbird-downflap.png")) {
//			std::cout << "Could not open the file";
//			return 0;
//		}
//		birdSprite.setTexture(birdTexture);
//		return 1;
//	}
//};
//
//
//
//
//
//struct Particle {
//    sf::Vector2f position;
//    sf::Vector2f oldPosition;
//};
//
//class VerletPhysics {
//public:
//    VerletPhysics(int width, int height) : width(width), height(height) {}
//
//
//    void addParticle(const sf::Vector2f& position) {
//        particles.push_back({ position, position });
//    }
//
//    void update(float deltaTime) {
//        for (Particle& particle : particles) {
//            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//            {
//                jump();
//
//            }
//            sf::Vector2f velocity = (particle.position - particle.oldPosition);
//            velocity += jumpVec(particle.position.x,jumpValue);
//            particle.oldPosition = particle.position;
//            particle.position += velocity + (gravityVec * 1.2f *deltaTime * deltaTime) ; // Gravity
//
//            // Simple collision with ground
//            if (particle.position.y >= height) {
//                particle.position.y = float(height);
//                particle.oldPosition.y = particle.position.y + velocity.y * 0.75f; // Damping
//            }
//
//        }
//    }
//
//    void jump() {
//        jumpValue += 20.1f;
//    }
//
//    const std::vector<Particle>& getParticles() const {
//        return particles;
//    }
//
//private:
//    std::vector<Particle> particles;
//    int width, height;  
//    float jumpValue = 0.f;
//    sf::Vector2f gravityVec{ 0, 75.f };
//    sf::Vector2f jumpVec;
//};
//
//int main() {
//
//    constexpr int Width = 800;
//    constexpr int Height = 600;
//    constexpr float TimeStep = 0.1f;
//    constexpr int MaxFrameRate = 60;
//
//    sf::Texture birdTexture;
//    sf::Sprite birdSprite;
//
//    sf::RenderWindow window(sf::VideoMode(Width, Height), "Verlet Integration");
//
//    VerletPhysics physics(Width, Height);
//    physics.addParticle(sf::Vector2f(Width / 2, Height / 4));
//
//    sf::Clock clock;
//
//    if (!birdTexture.loadFromFile("Assets/yellowbird-downflap.png")) {
//        std::cout << "Could not open the file";
//        return 0;
//    }
//    birdSprite.setTexture(birdTexture);
//
//    while (window.isOpen()) {
//
//        window.setFramerateLimit(MaxFrameRate);
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        float deltaTime = clock.restart().asSeconds();
//
//
//        physics.update(deltaTime);
//
//        window.clear(sf::Color::Black);
//
//        const std::vector<Particle>& particles = physics.getParticles();
//        for (const Particle& particle : particles) {
//            window.draw(birdSprite);
//            birdSprite.setPosition(particle.position);
//            
//        }
//
//
//        window.display();
//    }
//
//    return 0;
//}





