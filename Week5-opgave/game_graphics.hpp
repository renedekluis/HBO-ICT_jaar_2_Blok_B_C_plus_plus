#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include "rectangle.hpp"
#include "move.hpp"
#include "picture.hpp"

class game_graphics{
private:
	//variables;
	float tile_size = 256;
	std::vector<screen_objects*>tile_list;
	picture tic;
	picture tac;
	picture winner_tic;
	picture winner_tac;
	bool winner_is_known = false;
	sf::Texture texture;
	sf::Sprite sprite;
	char ascii_field[3][3] = {
		{ ' ', ' ', ' ' }, 
		{ ' ', ' ', ' ' },
		{ ' ', ' ', ' ' }
	};


	//functions
	screen_objects* get_new_screen_object(float x, float y);
	void draw_background(sf::RenderWindow & window);
	void draw_ascii_game();
	void clear_ascii_game();
public:
	void set_ascii_character(char ch, sf::Vector2f position);
	sf::Vector2f get_position_from_place(int place, bool background_creation = false);
	game_graphics();
	void create_background(sf::RenderWindow & window);
	void draw_move(sf::RenderWindow & window, std::string s, int place);
	void draw_game(sf::RenderWindow & window, std::vector<move*>move_list);
	int get_selected_tile(sf::Vector2f mouse_position);
	void draw_winner(std::string player, sf::RenderWindow & window);
	void set_winner(bool b);
	~game_graphics();
};

