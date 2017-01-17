#include "circle.hpp"


circle::circle(sf::Vector2f position, sf::Color color, int radius) :
	color(color),
	position(position),
	radius(float(radius))
{
	round.setRadius(float(radius));
	round.setPosition(position);
	round.setFillColor(color);
}

void circle::draw(sf::RenderWindow & window) const {
	window.draw(round);
}


sf::FloatRect circle::get_bounds() {
	return round.getGlobalBounds();
}


void circle::is_selected() {
	selected = true;
}
bool circle::check_selected() {
	return selected;
}
void circle::cancel_selected() {
	selected = false;
}

