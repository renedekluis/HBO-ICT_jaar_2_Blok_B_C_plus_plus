#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include "ball.hpp"
#include "player.hpp"


const struct {
	sf::Keyboard::Key Key;
	float x; float y;
}actions[] = {
	{ sf::Keyboard::Left,	-1,  0 },
	{ sf::Keyboard::Right,	+1,  0 },
	{ sf::Keyboard::Up,		 0, -1 },
	{ sf::Keyboard::Down,	 0, +1 }
};


class windowHandler {
private:
	sf::RenderWindow & window;
	sf::FloatRect player_bounds;
	sf::FloatRect ball_bounds;
	player my_player;
	ball my_ball;

public:
	windowHandler(sf::RenderWindow & window);
	void update();
	void draw();
	void check_collision();
	void move();


};

