#include "rectangle.hpp"


rectangle::rectangle(sf::RenderWindow & window, sf::Vector2f position, sf::Color color, sf::Vector2f end_position) :
	window(window),
	position(position),
	size(position-end_position),
	color(color)
{
	square.setSize(size);
	square.setFillColor(color);
	square.setPosition(windowSize.x / 2 - size.x / 2, windowSize.y - size.y);

}

void rectangle::draw() const {
	window.draw(square);
}

void rectangle::move(sf::Vector2f delta) {
	if (selected) {
		position += delta;
		square.setPosition(position);
	}

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


void rectangle::is_selected() {
	selected = true;
}
bool rectangle::check_selected() {
	return selected;
}
void rectangle::cancel_selected() {
	selected = false;
}