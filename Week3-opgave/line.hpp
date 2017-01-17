#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "color_convert.hpp"
#include "screen_objects.hpp"


class line : public screen_objects {
private:
	sf::Vector2f position;
	sf::Vector2f end_position;
	sf::Vector2f size = position - end_position;
	sf::RectangleShape square;
	sf::Color color;
	bool selected = false;


public:
	line(sf::Vector2f position, sf::Color color, sf::Vector2f size, float rotation);
	void draw(sf::RenderWindow & window) const override;
	void move(sf::Vector2f delta);
	sf::FloatRect get_bounds();
	std::string to_string();
	void is_selected();
	bool check_selected();
	void cancel_selected();
};

