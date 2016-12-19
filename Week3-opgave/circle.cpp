#include "circle.hpp"


circle::circle(sf::RenderWindow & window, sf::Vector2f position, sf::Color color, float radius) :
	window(window),
	radius(radius),
	position(position)
{
	position = window.getView().getSize();
	position.x /= 2;
	position.y /= 2;
	round.setRadius(radius);
}

void circle::draw() const {
	window.draw(round);
}

sf::Vector2f circle::move(sf::Vector2f delta) {

	if (position.x < 0) {
		position.x = 0;
	}
	else if (position.x >(windowSize.x - radius)) {
		position.x = float(windowSize.x - radius);
	}
	else if (position.y < 0) {
		position.y = 0;
	}
	else if (position.y >(windowSize.y - radius)) {
		position.y = float(windowSize.y - radius);
	}
	else {
		position += delta;
	}
	round.setPosition(position);
	return position;
}

sf::FloatRect circle::get_bounds() {
	return round.getGlobalBounds();
}


std::string circle::to_string() {
	std::ostringstream s;
	sf::FloatRect position = get_bounds();
	s << "CIRCLE (" 
		<< position.left 
		<< "," 
		<< position.top 
		<< ") "
		<< color_convert::color_to_string(color)
		<< " " 
		<< radius;
	return s.str();
}

