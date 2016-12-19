#include "color_convert.hpp"


sf::Color color_convert::string_to_color(std::string s) {
	for (auto const & color : colors) {
		if (color.name == s) {
			return color.color;
		}
	}
	throw unknown_color(s);
}

std::string color_convert::color_to_string(sf::Color kleur) {
	for (auto const & color : colors) {
		if (color.color == kleur) {
			return color.name;
		}
	}
	throw unknown_color("?");
}

