#include <iostream>
#include "object_editor.hpp"
#include <SFML/Graphics.hpp>

int main(void) {
	std::cout << "Starting application\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	char* filename = "object_data.txt";
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


/*
class movement -> bewegen
class screen_objects -> selecteren

factory() creeert:
	circle
	rectangle
	line
	picture 

objecten:
	bevatten positie
	bevatten een kleur behalve picture
	circle bevat diameter
	line en rectangle een eind punt

objecten staan opgeslagen in een text file


*/