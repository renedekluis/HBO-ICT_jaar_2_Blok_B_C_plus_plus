#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "color_convert.hpp"

class circle : public screen_object{


private:
	sf::RenderWindow & window;
	sf::Vector2f windowSize = window.getView().getSize();
	sf::Vector2f position;
	sf::Color color;
	float radius;
	sf::CircleShape round;
	

public:

	circle(sf::RenderWindow & window, sf::Vector2f position, sf::Color color , float radius = 30.0);

	void draw() const;

	sf::Vector2f move(sf::Vector2f delta);
	sf::FloatRect get_bounds();
	std::string to_string();
	
};

