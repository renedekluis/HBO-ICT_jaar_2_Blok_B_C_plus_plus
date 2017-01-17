#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "game_graphics.hpp"
#include "game_ascii.hpp"


const struct {
	sf::Keyboard::Key Key;
	int x;
}actions[] = {
	{ sf::Keyboard::Num1,	0 },
	{ sf::Keyboard::Num2,	1 },
	{ sf::Keyboard::Num3,	2 },
	{ sf::Keyboard::Num4,	3 },
	{ sf::Keyboard::Num5,	4 },
	{ sf::Keyboard::Num6,	5 },
	{ sf::Keyboard::Num7,	6 },
	{ sf::Keyboard::Num8,	7 },
	{ sf::Keyboard::Num9,	8 },

	{ sf::Keyboard::Numpad7,	0 },
	{ sf::Keyboard::Numpad8,	1 },
	{ sf::Keyboard::Numpad9,	2 },
	{ sf::Keyboard::Numpad4,	3 },
	{ sf::Keyboard::Numpad5,	4 },
	{ sf::Keyboard::Numpad6,	5 },
	{ sf::Keyboard::Numpad1,	6 },
	{ sf::Keyboard::Numpad2,	7 },
	{ sf::Keyboard::Numpad3,	8 }
};


class main_game{
private:
	game_graphics screen;
	game_ascii command_promt;
	sf::RenderWindow window{ sf::VideoMode{ 773, 773 }, "SFML window" };
	std::vector<move*>move_list;
	bool player_turn = 0;
	bool game_won = false;

	int horizontal_options[3][3] = {
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8}
	};
	int vertical_options[3][3] = {
		{ 0, 3, 6},
		{ 1, 4, 7},
		{ 2, 5, 8}
	};
	int diagnal_options[2][3] = {
		{ 6, 4, 2},
		{ 0, 4, 8}
	};


	void add_move(std::string player, int place);
	std::string get_player();
	bool check_game_won();
	bool check_horizontal(std::vector<int>move_positions);
	bool check_vertical(std::vector<int>move_positions);
	bool check_diagnal(std::vector<int>move_positions);
	void reset();
	int get_move_direction_from_button_keys();
public:
	main_game();
	void start_game();
	void game_loop();
	~main_game();
};

