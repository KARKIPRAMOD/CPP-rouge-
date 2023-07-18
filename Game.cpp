#include "Game.h"
//private Functions

void Game::initiVariables()
{
	this->window = nullptr;
	//Game Logic
	this->points = 0;
	this->enemySpwanTimerMax = 1000.f;
	this->enemySpwanTimer = this->enemySpwanTimerMax;
	this->maxEnemies = 5;
}

void Game::initWindow()
{
	this->VideoMode.height = 720 ;
	this->VideoMode.width = 1280;

	this->window = new sf::RenderWindow(this->VideoMode, "CPP ROGUE", sf::Style::Default);
	this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{
	this->enemy.setPosition(50.f, 50.f); 
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.f);
}

Game::Game()
{
	this->initiVariables();
	this->initWindow();
	this->initEnemies();


}
Game::~Game()
{
	delete this->window;

}

const bool Game::running() const
{

	return this->window->isOpen();
}

//functions


void Game::spawnEnemy()
{
	//Spawns enemy
	this->enemy.setPosition(
		//static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		0.f,
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x))
	);
	this->enemy.setFillColor(sf::Color::Green);

	//Spawn enemy
	this->enemies.push_back(this->enemy);
}

void Game::pollEvent()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;

		}
	}
}

void Game::update()
{
	this->pollEvent();
	this->updateEnemies();
}
void Game::render()
{
	//Renders the Game object 

	this->window->clear();
	
	
	//Draw game Object
	this->renderEnemies();
	//this->window->draw(this->enemy);

	this->window->display();
}

void Game::updateEnemies()
{
	//updating enemy timer for spwan
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpwanTimer >= this->enemySpwanTimerMax)
		{
			this->spawnEnemy();
			this->enemySpwanTimer = 0.f;
		}
		else
			this->enemySpwanTimer += 1.f;
	}

	//move the enemies
	for (auto& e : this->enemies)
	{
		e.move(0.f, 1.f);
	}
}

void Game::renderEnemies()
{
	for (auto& e : this->enemies)
	{
		this->window->draw(e);
	}
}
