#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class circle{


private:
	sf::Vector2f position;
	float radius;
	sf::RenderWindow & window;
	sf::CircleShape round;
	sf::Vector2f moveDirection;
	bool col_x = false;
	bool col_y = false;
	bool col = false;

public:

	circle(sf::RenderWindow & window, sf::Vector2f moveDirection = { 1,1 }, float size = 30.0);

	void draw() const;

	sf::Vector2f move();
	void collision_x();
	void collision_y();
	void collision();
	sf::FloatRect get_ball_bounds();

	void jump(sf::Vector2f target);



};

