#include "rectangle.hpp"


rectangle::rectangle(sf::RenderWindow & window, sf::Vector2f size) :
	window(window),
	size(size)
{
	position = window.getView().getSize();
	position.x = (position.x / 2) - (size.x / 2);
	position.y -= size.y;
	square.setSize(size);
	square.setPosition(windowSize.x / 2 - size.x / 2, windowSize.y - size.y);

}

void rectangle::draw() const {
	window.draw(square);
}

sf::Vector2f rectangle::move(sf::Vector2f delta) {
	if (!col) {
		if (position.x < 0) {
			position.x = 0;
		}
		else if (position.x >(windowSize.x - size.x)) {
			position.x = float(windowSize.x - size.x);
		}
		else if (position.y < 0) {
			position.y = 0;
		}
		else if (position.y >(windowSize.y - size.y)) {
			position.y = float(windowSize.y - size.y);
		}
		else {
			position += delta;
		}

		square.setPosition(position);
		return position;
	}
	else {

		square.setPosition(position);
		col = false;
		return position;
	}
}

sf::FloatRect rectangle::get_player_bounds() {
	return square.getGlobalBounds();
}

void rectangle::collision() {
	col = true;
}