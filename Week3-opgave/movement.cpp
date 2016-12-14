#include "movement.hpp"



movement::movement()
{
}

sf::Vector2f movement::move() {
	for (const auto& action : actions) {
		if (sf::Keyboard::isKeyPressed(action.Key)) {
			//my_player.move(sf::Vector2f{ action.x, action.y });
		}
	}
	return{ 0,0 };
}

movement::~movement()
{
}
