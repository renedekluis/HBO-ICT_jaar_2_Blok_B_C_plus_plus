#include "circle.hpp"





circle::circle(sf::RenderWindow & window, sf::Vector2f moveDirection, float radius) :
	window(window),
	radius(radius),
	moveDirection(moveDirection)
{
	position = window.getView().getSize();
	position.x /= 2;
	position.y /= 2;
	round.setRadius(radius);
}

void circle::draw() const {
	window.draw(round);
}

sf::Vector2f circle::move() {
	sf::Vector2f windowSize = window.getView().getSize();

	if (position.x < 0) {
		position.x = 0;
		moveDirection.x = -moveDirection.x;
	}
	if (position.x >(windowSize.x - 2 * radius)) {
		position.x = windowSize.x - 2 * radius;
		moveDirection.x = -moveDirection.x;
	}

	if (position.y >(windowSize.y - 2 * radius)) {
		position.y = windowSize.y - 2 * radius;
		moveDirection.y = -moveDirection.y;
	}
	if (position.y < 0) {
		position.y = 0;
		moveDirection.y = -moveDirection.y;
	}
	if (col_y) {
		moveDirection.y = -moveDirection.y;
	}
	if (col_x) {
		moveDirection.x = -moveDirection.x;
	}
	if (col) {
		moveDirection = -moveDirection;
	}

	position += moveDirection;
	round.setPosition(position);
	return position;
}

void circle::collision_x() {
	col_x = true;
	move();
	col_x = false;
}
void circle::collision_y() {
	col_y = true;
	move();
	col_y = false;
}
void circle::collision() {
	col = true;
	move();
	col = false;
}

sf::FloatRect circle::get_ball_bounds() {
	return round.getGlobalBounds();
}

void circle::jump(sf::Vector2f target) {
	position = target;
}

