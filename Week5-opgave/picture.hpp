#pragma once

#include <iostream>
#include <sstream>
#include <SFML\Graphics.hpp>
//#include "screen_objects.hpp"

class picture{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	std::string picture_path;
	sf::Vector2f location;

public:
	picture(std::string picture_path, sf::Vector2f location);
	void draw(sf::RenderWindow & window) const;
	void move(sf::Vector2f new_position);
	sf::FloatRect get_bounds();
	~picture();
};

