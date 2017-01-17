#pragma once
#include <SFML\Graphics.hpp>

const struct {
	sf::Keyboard::Key Key;
	float x; float y;
}actions[] = {
	{ sf::Keyboard::Left,	-1,  0 },
	{ sf::Keyboard::Right,	+1,  0 },
	{ sf::Keyboard::Up,		 0, -1 },
	{ sf::Keyboard::Down,	 0, +1 }
};

sf::Vector2f Vector2f_from_Vector2i(sf::Vector2i vector);


sf::Vector2f get_move_direction_from_button_keys();
sf::Vector2f get_mouse_position(sf::RenderWindow & window);
bool check_mouse();


