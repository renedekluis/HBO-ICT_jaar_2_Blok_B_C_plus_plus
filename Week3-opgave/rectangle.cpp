#include "rectangle.hpp"


rectangle::rectangle(sf::RenderWindow & window, sf::Vector2f position, sf::Color color, sf::Vector2f end_position) :
	window(window),
	position(position),
	end_position(end_position),
	color(color)
{
	square.setSize(end_position);
	square.setFillColor(color);
	square.setPosition(windowSize.x / 2 - size.x / 2, windowSize.y - size.y);

}

void rectangle::draw() const {
	window.draw(square);
}

sf::Vector2f rectangle::move(sf::Vector2f delta) {

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

sf::FloatRect rectangle::get_bounds() {
	return square.getGlobalBounds();
}


std::string rectangle::to_string() {
	std::ostringstream s;
	sf::FloatRect position = get_bounds();
	s << 
		"RECTANGLE (" 
		<< position.left 
		<< "," 
		<< position.top 
		<< ") "
		<< color_convert::color_to_string(color)
		<< " ("
		<< end_position.x
		<< "," 
		<< end_position.y 
		<< ")";
	return s.str();
}