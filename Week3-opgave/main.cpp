#include <iostream>
#include "object_editor.hpp"
#include <SFML/Graphics.hpp>

int main(void) {
	std::cout << "Starting application\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	std::string filename = "object_data.txt";
	object_editor edit(window, filename);

	while (window.isOpen()) {

		window.clear();
		edit.update();
		window.display();

		sf::sleep(sf::milliseconds(1));

		sf::Event event;
		if (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}


		

	}

	std::cout << "Terminating application\n";
	return 0;
}

