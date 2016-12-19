#pragma once

#include <iostream>
#include <sstream>
#include <SFML\Graphics.hpp>

class picture{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::RenderWindow & window;
	sf::Vector2f windowSize = window.getView().getSize();
	std::string picture_path;
	sf::Vector2f location;
public:
	picture(sf::RenderWindow & window, std::string picture_path, sf::Vector2f location);
	void draw() const;
	void move(sf::Vector2f delta);
	sf::FloatRect get_bounds();
	std::string to_string();
	~picture();
};

