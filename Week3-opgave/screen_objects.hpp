#pragma once

#include <SFML\Graphics.hpp>
#include "button_actions.hpp"

class screen_objects{
public:

	virtual void draw() const = 0;
	virtual void move(sf::Vector2f delta) = 0;
	virtual void is_selected() =0;
	virtual bool check_selected()=0;
	virtual void cancel_selected()=0;
	virtual sf::FloatRect get_bounds() = 0;
	virtual std::string to_string() = 0;

};

