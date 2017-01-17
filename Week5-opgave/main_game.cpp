#include "main_game.hpp"

bool check_mouse() {
	return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

sf::Vector2f Vector2f_from_Vector2i(sf::Vector2i vector) {
	return sf::Vector2f(static_cast<float>(vector.x), static_cast<float>(vector.y));
}

main_game::main_game() {}

void main_game::add_move(std::string player, int place) {
	for (auto move : move_list) {
		if (move->get_place() == place) {
			place = -1;
		}
	}

	if (place != -1) {
		move_list.push_back(new move(player, place));
		screen.draw_game(window, move_list);
		
		if (check_game_won()) {
			game_won = true;
		}
		else {
			player_turn = !player_turn;
		}
	}
	
}

std::string main_game::get_player() {
	if (player_turn == 0) {
		return "tic";
	}
	else {
		return "tac";
	}
}

bool main_game::check_horizontal(std::vector<int>move_positions) {
	int found_count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (auto move_position : move_positions) {
				if (horizontal_options[i][j] == move_position) {
					found_count++;
					break;
				}
			}
		}
		if (found_count >= 3) {
			return true;
		}
		else {
			found_count = 0;
		}
	}
	return false;
}

bool main_game::check_vertical(std::vector<int>move_positions) {
	int found_count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (auto move_position : move_positions) {
				if (vertical_options[i][j] == move_position) {
					found_count++;
					break;
				}
			}
		}
		if (found_count >= 3) {
			return true;
		}
		else {
			found_count = 0;
		}
	}
	return false;
}

bool main_game::check_diagnal(std::vector<int>move_positions) {
	int found_count = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (auto move_position : move_positions) {
				if (diagnal_options[i][j] == move_position) {
					found_count++;
					break;
				}
			}
		}
		if (found_count >= 3) {
			return true;
		}
		else {
			found_count = 0;
		}
	}
	return false;
}

bool main_game::check_game_won(){
	std::vector<int>tic_moves;
	std::vector<int>tac_moves;

	for(auto move : move_list){
		if (move->get_name() == "tic") {
			tic_moves.push_back(move->get_place());
		}
		else {
			tac_moves.push_back(move->get_place());
		}
		
	}

	return int(false) < (
		check_horizontal(tic_moves)
		+ check_vertical(tic_moves)
		+ check_diagnal(tic_moves)
		+ check_horizontal(tac_moves)
		+ check_vertical(tac_moves)
		+ check_diagnal(tac_moves)
		);
}


void main_game::start_game() {
	screen.create_background(window);
	screen.draw_game(window, move_list);
	game_loop();

}

void main_game::reset(){
	while (move_list.size() > 0) {
		move_list.pop_back();
	}
}


int main_game::get_move_direction_from_button_keys() {
	int number_pressed = -1;
	for (const auto& action : actions) {
		if (sf::Keyboard::isKeyPressed(action.Key)) {
			number_pressed = action.x;
		}
	}
	return number_pressed;
}

void main_game::game_loop(){
	std::string player;

	while (window.isOpen()) {
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {}
			reset();
			screen.draw_game(window, move_list);
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::U) && move_list.size() != 0) {
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {}
			move_list.pop_back();
			screen.draw_game(window,move_list);
			player_turn = !player_turn;
		}
		if (move_list.size() == 0) {
			game_won = false;
		}
		if (!game_won) {
			int button = get_move_direction_from_button_keys();
			if (button != -1) {
				add_move(get_player(), button);
			}
			if (check_mouse()) {
				while (check_mouse()) {}
				auto mouse = Vector2f_from_Vector2i(sf::Mouse::getPosition(window));
				add_move(get_player(), screen.get_selected_tile(mouse));
			}
			
			if (game_won) {
					
				//show winner
				std::cout << get_player() << " HEEFT GEWONNEN!!!\n";
				screen.set_winner(true);
				screen.draw_game(window, move_list);
					
					
				//reset to start
				sf::sleep(sf::milliseconds(2000));
					
				reset();
				screen.set_winner(false);
				game_won = false;
				screen.draw_game(window, move_list);
			}
		}

		sf::Event event;
		if (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		sf::sleep(sf::milliseconds(20));
	}
}

main_game::~main_game()
{
}
