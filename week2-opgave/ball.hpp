#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class ball {
private:
	sf::Vector2f position;
	float radius;
	sf::RenderWindow & window;
	sf::CircleShape circle;
	sf::Vector2f moveDirection;
	bool col_x = false;
	bool col_y = false;
	bool col = false;

public:

	ball(sf::RenderWindow & window, sf::Vector2f moveDirection = { 1,1 }, float size = 30.0);

	void draw() const;

	sf::Vector2f move();
	void collision_x();
	void collision_y();
	void collision();
	sf::FloatRect get_ball_bounds();

	void jump( sf::Vector2f target );


};

#endif
