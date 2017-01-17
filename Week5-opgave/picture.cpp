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

void picture::move(sf::Vector2f new_position) {
	location = new_position;
	sprite.setPosition(location);
}

sf::FloatRect picture::get_bounds() {
	return sprite.getGlobalBounds();
}



picture::~picture()
{
}
