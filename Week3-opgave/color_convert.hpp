#ifndef _COLOR_CONVERT_HPP
#define _COLOR_CONVERT_HPP

#include <SFML/Graphics.hpp>
#include "exception_list.hpp"
#include <vector>

typedef struct {
	std::string name; 
	sf::Color color_value;
}string_and_colors;

class color_convert{
private:
	static string_and_colors colors[];
public:
	static sf::Color string_to_color(std::string color);
	static std::string color_to_string(sf::Color color);
};
#endif //COLOR_CONVERT_HPP








