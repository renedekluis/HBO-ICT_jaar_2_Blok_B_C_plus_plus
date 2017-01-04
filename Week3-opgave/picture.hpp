#pragma once

#include <iostream>
#include <sstream>
#include <SFML\Graphics.hpp>
#include "screen_objects.hpp"

class picture: public screen_objects{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::RenderWindow & window;
	sf::Vector2f windowSize = window.getView().getSize();
	std::string picture_path;
	sf::Vector2f location;
	bool selected = false;
public:
	picture(sf::RenderWindow & window, std::string picture_path, sf::Vector2f location);
	void draw() const override;
	void move(sf::Vector2f delta);
	sf::FloatRect get_bounds();
	std::string to_string();
	void is_selected();
	bool check_selected();
	void cancel_selected();
	~picture();
};

