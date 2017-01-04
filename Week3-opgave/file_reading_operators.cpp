#include "file_reading_operators.hpp"


std::ifstream & operator >> (std::ifstream & input, sf::Vector2f & rhs) {
	char c;
	if (!(input >> c)) { throw end_of_file(); }

	if (c != '(') { throw invalid_position(c); }

	if (!(input >> rhs.x)) { throw invalid_position(c); }

	if (!(input >> c)) { throw invalid_position(c); }

	if (c != ',') { throw invalid_position(c); }

	if (!(input >> rhs.y)) { throw invalid_position(c); }

	if (!(input >> c)) { throw invalid_position(c); }

	if (c != ')') { throw invalid_position(c); }

	return input;
}

std::ifstream & operator >> (std::ifstream & input, char & rhs) {
	rhs = input.get();
	return input;
}

std::ifstream & operator >> (std::ifstream & input, float & rhs) {
	char c;
	rhs = 0.0;
	for (;;) {
		c = input.peek();
		if (c >= '0' && c <= '9') {
			rhs *= 10 + (c - '0');
		}
		else if (rhs != 0.0) {
			break;
		}
		input.get();
	}
	return input;
}

std::ifstream & operator >> (std::ifstream & input, sf::Color & rhs) {
	std::string s;
	input >> s;
	rhs = color_convert::string_to_color(s);
	return input;
}

std::ifstream & operator >> (std::ifstream & input, std::string & rhs) {
	char c;
	rhs = "";
	for (;;) {
		c = input.get();
		if (c == '\0' || c == '\n' || c == ' ') {
			if (rhs != "") {
				break;
			}
		}
		else if (c != '\r') {
			rhs += c;
		}
	}
	return input;
}

std::ostream& operator<<(std::ostream &strm, const screen_objects &screen_obj) {
	return strm << const_cast<screen_objects&>(screen_obj).to_string();
}