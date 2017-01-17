#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>


class circle{


private:
	sf::Vector2f position;
	sf::Color color;
	float radius;
	sf::CircleShape round;
	bool selected = false;

public:
	circle(sf::Vector2f position, sf::Color color = sf::Color::White, int radius = 70);
	void draw(sf::RenderWindow & window) const;
	sf::FloatRect get_bounds();
	void is_selected();
	bool check_selected();
	void cancel_selected();
};

