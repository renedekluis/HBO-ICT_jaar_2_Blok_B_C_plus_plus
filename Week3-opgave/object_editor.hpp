#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <list>
#include "screen_objects.hpp"
#include "exception_list.hpp"
#include "file_reading_operators.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "picture.hpp"

using namespace std;


class object_editor{
private:
	sf::RenderWindow & window;
	std::string filename_object_data;
	std::ifstream input(filename_object_data);
	std::list<char*>object_list;
public:
	object_editor(sf::RenderWindow & window, std::string filename_object_data);
	sf::Vector2f object_editor::Vector2f_from_Vector2i(sf::Vector2i vector);
	void save(std::list<screen_objects*> screen_objects);
	void redraw(sf::RenderWindow &window, std::list<screen_objects*> screen_objects);
	screen_objects * screen_object_read(std::ifstream & input);

	void update();
	~object_editor();
};

