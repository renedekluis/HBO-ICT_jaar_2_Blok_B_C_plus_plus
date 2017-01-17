#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "color_convert.hpp"
#include "screen_objects.hpp"

class circle : public screen_objects{


private:
	sf::Vector2f position;
	sf::Color color;
	float radius;
	sf::CircleShape round;
	bool selected = false;

public:
	circle(sf::Vector2f position, sf::Color color = sf::Color::White, int radius = 70);
	void draw(sf::RenderWindow & window) const override;
	void move(sf::Vector2f delta);
	sf::FloatRect get_bounds();
	std::string to_string();
	void is_selected();
	bool check_selected();
	void cancel_selected();
};

