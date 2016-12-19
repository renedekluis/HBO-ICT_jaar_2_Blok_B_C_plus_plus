#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "color_convert.hpp"


class rectangle{
private:
	sf::RenderWindow & window;
	sf::Vector2f windowSize = window.getView().getSize();
	sf::Vector2f position;
	sf::Vector2f end_position;
	sf::Vector2f size = position - end_position;
	sf::RectangleShape square;
	sf::Color color;


public:
	rectangle(sf::RenderWindow & window, sf::Vector2f position, sf::Color color, sf::Vector2f end_position);
	void draw() const;
	sf::Vector2f move(sf::Vector2f delta);
	sf::FloatRect get_bounds();
	std::string to_string();
};

