#include "picture.hpp"


picture::picture(sf::RenderWindow & window, std::string picture_path, sf::Vector2f location) :
	window(window),
	picture_path(picture_path),
	location(location)
{
	if (!texture.loadFromFile(
			picture_path, 
			sf::IntRect(int(location.x), int(location.y), int(texture.getSize().x), int(texture.getSize().y))
			)
		){
		std::cout << "Error while loding file.\n";
	}
	texture.setSmooth(true);
	sprite.setTexture(texture);
}


void picture::draw() const{
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
		"PICTURE (" 
		<< position.left 
		<< "," 
		<< position.top 
		<< ") "
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
