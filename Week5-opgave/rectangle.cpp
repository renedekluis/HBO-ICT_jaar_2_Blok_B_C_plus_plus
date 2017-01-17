#include "rectangle.hpp"


rectangle::rectangle(sf::Vector2f position, sf::Color color, sf::Vector2f end_position) :
	position(position),
	size(end_position - position),
	color(color)
{
	square.setSize(size);
	square.setFillColor(color);
	square.setPosition(position);
}

void rectangle::draw(sf::RenderWindow & window) const {
	window.draw(square);
}


sf::FloatRect rectangle::get_bounds() {
	return square.getGlobalBounds();
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