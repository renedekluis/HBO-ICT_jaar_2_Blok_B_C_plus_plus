#include "button_actions.hpp"





sf::Vector2f button_actions::move() {
	move_direction = { 0,0 };
	for (const auto& action : actions) {
		if (sf::Keyboard::isKeyPressed(action.Key)) {
			move_direction = sf::Vector2f{ action.x, action.y };
		}
	}
	return move_direction;
}

 sf::Vector2f button_actions::get_mouse_position(sf::RenderWindow & window) {
	return Vector2f_from_Vector2i(sf::Mouse::getPosition(window));
}

bool button_actions::check_mouse() {
	 if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		 return true;
	}
	 else {
		 return false;
	 }
}

