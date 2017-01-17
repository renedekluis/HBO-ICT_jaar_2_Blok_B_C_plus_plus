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

void circle::move(sf::Vector2f delta) {
	if (selected) {
		position += delta;
		round.setPosition(position);
	}
}

sf::FloatRect circle::get_bounds() {
	return round.getGlobalBounds();
}


std::string circle::to_string() {
	std::ostringstream s;
	s << "(" 
		<< position.x 
		<< "," 
		<< position.y 
		<< ") CIRCLE "
		<< color_convert::color_to_string(color)
		<< " " 
		<< radius;
	return s.str();
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

