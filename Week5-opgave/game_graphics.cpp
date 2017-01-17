#include "game_graphics.hpp"



game_graphics::game_graphics():
	tic("x.png", { 0,0 }),
	tac("circle.png", { 0,0 }),
	winner_tic("x_wins.png", { 100,100 }),
	winner_tac("circle_wins.png", { 100,100 })
{}

screen_objects*  game_graphics::get_new_screen_object(float x, float y) {
	return new rectangle({ x + 5, y + 5 }, sf::Color::Green, { x + tile_size, y + tile_size });
}

sf::Vector2f game_graphics::get_position_from_place(int place, bool background_creation ) {
	float y_level = 0, x = 0, y = 0;
	for (int i = 0; i <= place; i++) {
		if (i % 3 == 0 && i != 0) {
			y_level += 1;
		}
		x = ((i % 3)*tile_size);
		y = y_level*tile_size;
		if (background_creation) {
			tile_list.push_back(get_new_screen_object(x, y));
		}
	}
	return{ x, y };
}

void game_graphics::create_background(sf::RenderWindow & window) {
	get_position_from_place(9, true);
}

void game_graphics::draw_background(sf::RenderWindow & window) {
	for (auto list :  tile_list) {
		list->draw(window);
	}
}

void game_graphics::draw_ascii_game() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << ascii_field[i][j];
			std::cout << (j < 2 ? '|' : '\n');
		}
		std::cout << (i < 2 ? "-----\n" : "");
	}
}

void game_graphics::set_ascii_character(char ch, sf::Vector2f position) {
	ascii_field[int(position.y / tile_size)][int(position.x / tile_size)] = ch;
}

void game_graphics::draw_move(sf::RenderWindow & window, std::string s, int place) {
	sf::Vector2f position = get_position_from_place(place);
	if (s == "tic") {
		tic.move(position);
		tic.draw(window);
		set_ascii_character('X', position);
	}
	else{
		tac.move(position);
		tac.draw(window);
		set_ascii_character('O',position);
	}
	
}
void game_graphics::clear_ascii_game() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ascii_field[i][j] = ' ';
		}
	}
}

void game_graphics::draw_winner(std::string player, sf::RenderWindow & window) {
	if (player == "tic") {
		winner_tic.draw(window);
	}
	else {
		winner_tac.draw(window);
	}
}

void game_graphics::draw_game(sf::RenderWindow & window, std::vector<move*>move_list){
	window.clear();
	draw_background(window);

	clear_ascii_game();

	for (auto move : move_list) {
		draw_move(window, move->get_name(), move->get_place());
	}

	draw_ascii_game();
	std::cout << "\n\n";
	if (winner_is_known) {
		draw_winner(move_list[move_list.size()-1]->get_name(),window);
	}
	window.display();
}

void game_graphics::set_winner(bool b) {
	winner_is_known = b;
}

int game_graphics::get_selected_tile(sf::Vector2f mouse_position) {
	int i = 0;
	for (auto tile : tile_list) {
		if (tile->get_bounds().contains(mouse_position)) {
			return i;
		}
		i++;
	}
	return -1;
}

game_graphics::~game_graphics()
{
}