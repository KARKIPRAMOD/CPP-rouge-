#pragma once


#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<iostream>
#include<vector>
#include<ctime>
class Game
{
private:

	//variables
	// window
	sf::RenderWindow* window;
	sf::VideoMode VideoMode;
	sf::Event ev;

	//Game Logic
	int points;
	float enemySpwanTimer;
	float enemySpwanTimerMax;
	int maxEnemies;

	// Game Object
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;



	//private functions
	void initiVariables();
	void initWindow();
	void initEnemies();

public:

	//constructors and dectructors
	Game();
	virtual ~Game();

	//Accessor
	const bool running() const;



	//functions
	void spawnEnemy();
	void pollEvent();
	void update();
	void render();
	void updateEnemies();
	void renderEnemies();

};

