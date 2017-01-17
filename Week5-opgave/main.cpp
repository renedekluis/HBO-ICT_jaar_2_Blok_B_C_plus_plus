#include <iostream>
#include <SFML/Graphics.hpp>
#include "main_game.hpp"

int main(void) {
	
	std::cout << "Starting application\n";
	main_game game;

	game.start_game();

	std::cout << "Terminating application\n";
	return 0;
}