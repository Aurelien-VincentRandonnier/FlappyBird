#include "Game.h"

Game::Game()
{
	window = nullptr;
	initWindow();
	window->setKeyRepeatEnabled(false);
	windowWidth = (float)this->videoMode.height;

	#pragma region ADD GAME OBJECT
	player = nullptr;
	addPlayer(),
#pragma endregion

	clock.restart();

	#pragma region FontLoad
	if(!arialFont.loadFromFile("Assets/Fonts/Arial.ttf"))
		std::cerr << "can't load font" << "\n";
	textCollisionOutputUP.setFont(arialFont);
	textCollisionOutputUP.setCharacterSize(40);
	textCollisionOutputUP.setFillColor(sf::Color::White);

	textCollisionOutputLP.setFont(arialFont);
	textCollisionOutputLP.setCharacterSize(40);
	textCollisionOutputLP.setFillColor(sf::Color::White);
	textCollisionOutputLP.move(windowWidth/2, 40);

#pragma endregion
}

Game::~Game()
{
	delete this->window;
	for (GameObject* obj : gameObjectArray) {
		delete obj;
	}
}

void Game::run() {
	//initialise la fenetre


	//boucle de jeu
	while (this->window->isOpen()) {
		while (this->window->pollEvent(this->event)) {
			if (this->event.type == sf::Event::Closed)
				this->window->close();
		}
		// calcule le temps entre l'image et l'image précedente
		deltaTime = clock.restart().asSeconds();

		genreateLevel();
		updateAll();

	}
}

void Game::addGameObject(GameObject* gameObject)
{
	gameObjectArray.push_back(gameObject);
}

void Game::initWindow()
{
	this->videoMode.height = 1400;
	this->videoMode.width = 1200;
	this->window = new sf::RenderWindow(this->videoMode, "Game");
}

void Game::updateAll()
{
	this->window->clear();
	for (GameObject* obj : gameObjectArray) {
		obj->update(this->window, deltaTime);
		obj->render(this->window);
	}

	//TO-DO put refference of pipeArray element in GOarray to make only one loop and remove the pipe array loop
	system("cls");
	for (Pipe* pipe : pipeArray) {
		if (pipe->getPipePosition().x > -100.f) {
			pipe->update(this->window, deltaTime);
			pipe->render(this->window);
			addScore(pipe);
			playerCollisionPipe(pipe);
		} else
			pipeArray.erase(pipeArray.begin());
	}
	// playerCollisionPipe();
	this->window->display();
}

void Game::addPlayer()
{
	player = new Player({ 600,500 });
	addGameObject(player);
}

void Game::genreateLevel()
{	
	if (clockPipeFrenquecy.getElapsedTime().asSeconds() >= 3) {
		int tempRand = std::rand() % 300-500;
		pipeArray.push_back(new Pipe({ windowWidth, (float)tempRand }));
		pipeArray.push_back(new Pipe({ windowWidth , (float)tempRand + pipeArray[0]->getPipeSize().y + spacing}));
		clockPipeFrenquecy.restart();
	}
}

void Game::playerCollisionPipe(Pipe* pipe)
{
	if (player->collision(pipe->getPipeBounds())) {
		textCollisionOutputUP.setString("collide with pipe");
		window->draw(textCollisionOutputUP);
		pipeArray.clear();
		score = 0;
		player->resetPos();
	}
	textCollisionOutputUP.setString("");
	window->draw(textCollisionOutputUP);
}

void Game::addScore(Pipe* pipe)
{
	if (!pipe->hadPassed && pipe->getPipePosition().x < player->playerPosition.x) {
		score+=0.5;
		pipe->hadPassed = true;
	}
	textCollisionOutputLP.setString(std::to_string((int)score));
	window->draw(textCollisionOutputLP);
}

float Game::getDeltaTime()
{
	return deltaTime;
}

