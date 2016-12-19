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

sf::Vector2f Vector2f_from_Vector2i(sf::Vector2i vector) {
	return sf::Vector2f(static_cast<float>(vector.x), static_cast<float>(vector.y));
}

class button_actions {
private:
	sf::Vector2f move_direction;
public:
	sf::Vector2f move();
	sf::Vector2f get_mouse_position(sf::RenderWindow & window);
	bool check_mouse();
};

