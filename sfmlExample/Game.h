#pragma once
#include <sfml/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
/*
class that acts as  game engine
wrapper class
*/
class Game
{
private:
	//variables
	// window
	sf::RenderWindow* window;
	sf::Event ev;
	//Game objects
	sf::CircleShape ball;
	sf::RectangleShape player,player2;
	sf::Vector2f pos,pos2,ballPos,vel;
//private function
	void initializevariables();
	void initwindow();
	void initObjects();
	void ballMovement();
	void player1Pos();
	void player2Pos();
public:
	//CONSTRUCTORS/DESTRUCTORS
	Game();
	virtual ~Game();
	//Accessors
	const bool getwindowIsOpen() const;
	//functions
	void pollEvents();
	void update();
	void render();
};

