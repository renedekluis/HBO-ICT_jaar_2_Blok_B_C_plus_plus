#include "player.hpp"

player::player(sf::RenderWindow & window, sf::Vector2f size) :
	window(window),
	size(size)
{
	position = window.getView().getSize();
	position.x = (position.x/2) - (size.x / 2);
	position.y -=  size.y;
	rectangle.setSize(size);
	rectangle.setPosition(windowSize.x/2 - size.x/2, windowSize.y  - size.y);

}

void player::draw() const{	
	window.draw(rectangle);
}

sf::Vector2f player::move(sf::Vector2f delta) {
	if (!col) {
		if (position.x < 0) {
			position.x = 0;
		}
		else if (position.x > (windowSize.x - size.x)) {
			position.x = float(windowSize.x - size.x);
		}
		else if (position.y < 0) {
			position.y = 0;
		}
		else if (position.y > (windowSize.y - size.y)) {
			position.y = float(windowSize.y - size.y);
		}
		else {
			position += delta;
		}
		
		rectangle.setPosition(position);
		return position;
	}
	else {
		
		rectangle.setPosition(position);
		col = false;
		return position;
	}
}

sf::FloatRect player::get_player_bounds() {
	return rectangle.getGlobalBounds();
}

void player::collision() {
	col = true;
}