
#include "ball.hpp"


ball::ball( sf::RenderWindow & window , sf::Vector2f moveDirection, float radius):
	window(window),
	radius(radius),
	moveDirection(moveDirection)
{
	position = window.getView().getSize();
	position.x /= 2;
	position.y /= 2;
	circle.setRadius(radius);
}

void ball::draw() const {
	window.draw(circle);
}

sf::Vector2f ball::move() {
	sf::Vector2f windowSize = window.getView().getSize();

	if (position.x < 0) {
		position.x = 0;
		moveDirection.x = -moveDirection.x;
	}
	if (position.x > (windowSize.x - 2 * radius)) {
		position.x = windowSize.x - 2 * radius;
		moveDirection.x = -moveDirection.x;
	}

	if (position.y >(windowSize.y - 2 * radius)) {
		position.y = windowSize.y - 2 * radius;
		moveDirection.y = -moveDirection.y;
	}
	if (position.y < 0 ) {
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
	circle.setPosition(position);
	return position;
}

void ball::collision_x() {
	col_x = true;
	move();
	col_x = false;
}
void ball::collision_y() {
	col_y = true;
	move();
	col_y = false;
}
void ball::collision() {
	col = true;
	move();
	col = false;
}

sf::FloatRect ball::get_ball_bounds() {
	return circle.getGlobalBounds();
}

void ball::jump( sf::Vector2f target ) {
	position = target;
}
