#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include "screen_objects.hpp"
#include "exception_list.hpp"
#include "file_reading_operators.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "picture.hpp"
#include "button_actions.hpp"


class object_editor{
private:
	sf::RenderWindow & window;
	std::string filename_object_data;
	std::ifstream input;
	std::vector<screen_objects*>object_list;
	


public:
	object_editor(sf::RenderWindow & window, std::string filename_object_data);
	void update();
	screen_objects * screen_object_read(std::ifstream & input);
	void save(std::vector<screen_objects*> screen_objects);
	sf::Vector2f object_editor::Vector2f_from_Vector2i(sf::Vector2i vector);
	
	~object_editor();
};

