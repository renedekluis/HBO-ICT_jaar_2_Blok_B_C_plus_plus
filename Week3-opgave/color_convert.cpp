#include "color_convert.hpp"



sf::Color color_convert::string_to_color(std::string s) {
	string_and_colors colors[]{
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

	for (auto const color : colors) {
		if (color.name == s) {
			return color.color_value;
		}
	}
	throw unknown_color(s);
}

std::string color_convert::color_to_string(sf::Color kleur) {
	string_and_colors colors[]{
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

	for (auto const & colour : colors) {
		if (colour.color_value == kleur) {
			return colour.name;
		}
	}
	//std::cout << "Color not found.\n";
	throw unknown_color("?");
}

