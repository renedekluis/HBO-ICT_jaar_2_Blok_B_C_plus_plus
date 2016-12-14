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

class movement{
private:
	
public:
	movement();
	sf::Vector2f move();
	~movement();
};

