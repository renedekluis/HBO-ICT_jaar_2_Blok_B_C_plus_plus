#include "picture.hpp"




picture::picture(sf::RenderWindow & window, std::string picture_path, sf::Vector2f location) :
	window(window),
	picture_path(picture_path),
	location(location)
{
	if (!texture.loadFromFile(
			picture_path, 
			sf::IntRect(location.x, location.y, texture.getSize().x, texture.getSize().y)
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
	location += move_direction;
	sprite.setPosition(location);
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

picture::~picture()
{
}
