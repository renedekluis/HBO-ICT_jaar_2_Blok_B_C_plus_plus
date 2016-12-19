#pragma once

#include <SFML/Graphics.hpp>


class unknown_color : public std::exception {
public:
	unknown_color(const std::string & name) :
		s{ std::string{ "unknown color [" } +name + "]" }
	{}

	const char * what(){
		return s.c_str();
	}

private:
	std::string s;
};


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








