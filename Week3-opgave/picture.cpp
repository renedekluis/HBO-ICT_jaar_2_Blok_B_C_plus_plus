#include "picture.hpp"


picture::picture(std::string picture_path, sf::Vector2f location) :
	picture_path(picture_path),
	location(location)
{
	if (!texture.loadFromFile(picture_path)){
		std::cout << "Error while loding file.\n";
	}
	sprite.setPosition(location);
	texture.setSmooth(true);
	sprite.setTexture(texture);
}


void picture::draw(sf::RenderWindow & window) const{
	window.draw(sprite);
}

void picture::move(sf::Vector2f move_direction) {
	if (selected) {
		location += move_direction;
		sprite.setPosition(location);
	}
}

sf::FloatRect picture::get_bounds() {
	return sprite.getGlobalBounds();
}

std::string picture::to_string(){
	std::ostringstream s;
	sf::FloatRect position = get_bounds();
	s << 
		"(" 
		<< position.left 
		<< "," 
		<< position.top 
		<< ") PICTURE "
		<< picture_path;
	return s.str();
}


void picture::is_selected() {
	selected = true;
}
bool picture::check_selected() {
	return selected;
}
void picture::cancel_selected() {
	selected = false;
}

picture::~picture()
{
}
