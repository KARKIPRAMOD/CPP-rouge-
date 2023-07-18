#include<iostream>
#include"Game.h"
int main()
{
	srand(static_cast<unsigned>(time(NULL)));
	Game game;



	// game loop
	while(game.running())
	{
		//Update
		game.update();

		//Render
		game.render();
	}



	return 0;
}