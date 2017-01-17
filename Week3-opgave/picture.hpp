#pragma once

#include <iostream>
#include <sstream>
#include <SFML\Graphics.hpp>
#include "screen_objects.hpp"

class picture: public screen_objects{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	std::string picture_path;
	sf::Vector2f location;
	bool selected = false;
public:
	picture(std::string picture_path, sf::Vector2f location);
	void draw(sf::RenderWindow & window) const override;
	void move(sf::Vector2f delta);
	sf::FloatRect get_bounds();
	std::string to_string();
	void is_selected();
	bool check_selected();
	void cancel_selected();
	~picture();
};

