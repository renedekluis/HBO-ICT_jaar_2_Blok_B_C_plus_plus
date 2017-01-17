#include "line.hpp"


line::line(sf::Vector2f position, sf::Color color, sf::Vector2f size, float rotation) :
	position(position),
	size(size),
	color(color)
{
	square.setSize(size);
	square.setFillColor(color);
	square.setPosition(position);
	square.setRotation(rotation);
}

void line::draw(sf::RenderWindow & window) const {
	window.draw(square);
}

void line::move(sf::Vector2f delta) {
	if (selected) {
		position += delta;
		square.setPosition(position);
	}
}

sf::FloatRect line::get_bounds() {
	return square.getGlobalBounds();
}


std::string line::to_string() {
	std::ostringstream s;
	s << "("
		<< position.x
		<< ","
		<< position.y
		<< ") LINE "
		<< color_convert::color_to_string(color)
		<< " ("
		<< size.x
		<< ","
		<< size.y
		<< ") "
		<< square.getRotation();
	return s.str();
}


void line::is_selected() {
	selected = true;
}
bool line::check_selected() {
	return selected;
}
void line::cancel_selected() {
	selected = false;
}