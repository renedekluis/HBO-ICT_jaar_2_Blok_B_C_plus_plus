#include <iostream>
#include <SFML/Graphics.hpp>
#include "windowHandler.hpp"


int main( int argc, char *argv[] ){
	std::cout << "Starting application\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	windowHandler ctrl(window);
	
	while(window.isOpen()){

		
		sf::Event event;
		if( window.pollEvent(event) ){
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();
		ctrl.update();
		window.display();

		sf::sleep(sf::milliseconds(1));

	}

	std::cout << "Terminating application\n";
	return 0;
}

