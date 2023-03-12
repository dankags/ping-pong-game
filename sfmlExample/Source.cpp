#include <iostream>
#include "Game.h"
using namespace std;
int main(int argc,char* argv[]) {
	//Init Game Engine
	Game game;
	//Game loop
	while (game.getwindowIsOpen())
	{
	   //poll event updates	
		game.update();

		//render Game and its objects
		game.render();
		
	}
	return 0;
}