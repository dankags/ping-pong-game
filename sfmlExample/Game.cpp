#include "Game.h"

//constructor and destructor
Game::Game() {
	this->initializevariables();
	this->initwindow();
	this->initObjects();
}
Game::~Game() {
	delete this->window;
}
//private functions
void Game::initializevariables() {
	this->window = nullptr;
	
}
void Game::initwindow() {
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "dankags");

}
void Game::initObjects()
{   //player1
	this->pos.x =778.f;
	this->pos.y = 400.f;
	this->player.setSize(sf::Vector2f(20.f, 100.f));
	this->player.setFillColor(sf::Color::Cyan);
	this->player.setOutlineColor(sf::Color::Color(255,0,10));
	this->player.setOutlineThickness(1.f);
	this->player.setPosition(sf::Vector2f(pos));
	//player2
	this->pos2.x = 1.f;
	this->pos2.y = 400.f;
	this->player2.setSize(sf::Vector2f(20.f, 100.f));
	this->player2.setFillColor(sf::Color::Green);
	this->player2.setOutlineColor(sf::Color::Color(255, 0, 60));
	this->player2.setOutlineThickness(1.f);
	this->player2.setPosition(sf::Vector2f(pos2));
	//ball
	this->ballPos.x = 400.f;
	this->ballPos.y = 400.f;
	vel.x = 1.f;
	vel.y = 1.f;
	this->ball.setRadius(15.f);
	this->ball.setFillColor(sf::Color::White);
	this->ball.setOutlineThickness(2.f);
	this->ball.setOutlineColor(sf::Color::Color(110,20,200));
	this->ball.setPosition(sf::Vector2f(ballPos));
}
void Game::ballMovement()
{
	if (ball.getGlobalBounds().intersects(player.getGlobalBounds())|| ball.getGlobalBounds().intersects(player2.getGlobalBounds()))
	{
		vel.x *= -1;
		//vel.y *= -1;
		//ballPos.y += vel.y;
		ballPos.x += vel.x;
		this->ball.setPosition(ballPos);
	}
	else {

		if (ballPos.x < 0 || ballPos.x>(800 - 17)) {
			vel.x *= -1;
		}
		if (ballPos.y < 0 || ballPos.y >(600 - 17)) {
			vel.y *= -1;
		}
		ballPos.x += vel.x;
		ballPos.y += vel.y;
		this->ball.setPosition(sf::Vector2f(ballPos));
	}
}
void Game::player1Pos()
{   //player 1
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (this->pos.y > 1.f)
		{
			pos.y -= 1.1;
			this->player.setPosition(this->pos);
		}

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (this->pos.y < (600.f - 101.f))
		{
			pos.y += 1.1;
			this->player.setPosition(this->pos);
		}
	}
	
}
void Game::player2Pos() {
	//player 2
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (this->pos2.y < (600.f - 101.f))
		{
			pos2.y += 1.1;
			this->player2.setPosition(this->pos2);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (this->pos2.y > 1.f)
		{
			pos2.y -= 1.1;
			this->player2.setPosition(this->pos2);
		}
	}


}
//public function

const bool Game::getwindowIsOpen() const
{
	return this->window->isOpen();
}
void Game::pollEvents()
{   //event polling
	while (this->window->pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed) {
			this->window->close();
		}
	}
	
}

void Game::update() {
	//updates objects in the game 
	this->pollEvents();
	this->player1Pos();
	this->player2Pos();
	this->ballMovement();
}
void Game::render() {
	/*
	- display frame in window
	- renders objects
	- clears old frame
	Renders game objects
	*/
	this->window->clear();
	//draw game objects
	this->window->draw(this->ball);
	this->window->draw(this->player);
	this->window->draw(this->player2);
	this->window->display();
}
