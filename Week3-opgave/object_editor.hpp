#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <list>
#include "screen_objects.hpp"

using namespace std;

class object_editor{
private:
	sf::RenderWindow & window;
	char* filename_object_data;
	screen_objects objects;
	std::list<char*>object_list;
public:
	object_editor(sf::RenderWindow & window, char* filename_object_data);
	void update();
	~object_editor();
};

