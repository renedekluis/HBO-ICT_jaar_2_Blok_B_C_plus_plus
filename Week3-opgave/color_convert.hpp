#pragma once

#include <SFML/Graphics.hpp>
#include "exception_list.hpp"



const struct {
	std::string name; sf::Color color;
}colors[]{
	{ "red", sf::Color::Red },
	{ "yellow", sf::Color::Yellow },
	{ "green", sf::Color::Green },
	{ "blue", sf::Color::Blue },
	{ "black", sf::Color::Black },
	{ "white", sf::Color::White },
	{ "magenta", sf::Color::Magenta },
	{ "cyan", sf::Color::Cyan },
	{ "transparent", sf::Color::Transparent }
};

class color_convert{
public:
	static sf::Color string_to_color(std::string color);
	static std::string color_to_string(sf::Color color);
};








