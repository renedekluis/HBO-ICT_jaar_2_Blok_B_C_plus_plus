#pragma once

#include <SFML\Graphics.hpp>

class screen_objects{
public:
	screen_objects();
	virtual void draw(sf::RenderWindow & window) = 0;
	virtual void move(sf::Vector2f delta)=0;
	virtual sf::FloatRect get_bounds() = 0;
	virtual std::string to_string() = 0;
	~screen_objects();
};

