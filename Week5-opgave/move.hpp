#pragma once

#include <iostream>


class move{
private:
	std::string move_name;
	int place;
public:
	move(std::string move_name, int place);
	std::string get_name();
	int get_place();
	~move();
};

