#include "move.hpp"



move::move(std::string move_name, int place):
	move_name(move_name),
	place(place)
{}

std::string move::get_name() {
	return move_name;
}

int move::get_place() {
	return place;
}

move::~move(){
}
