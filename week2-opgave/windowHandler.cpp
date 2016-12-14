#include "windowHandler.hpp"


windowHandler::windowHandler(sf::RenderWindow & window) :
	window(window),
	my_ball(window),
	my_player(window)

{}


void windowHandler::update() {
	move();
	check_collision();
	draw();

}

void windowHandler::draw() {
	my_ball.draw();
	my_player.draw();
}


void windowHandler::check_collision() {
	player_bounds = my_player.get_player_bounds();
	ball_bounds = my_ball.get_ball_bounds();

	if (player_bounds.intersects(ball_bounds)) {
		bool col_x = (ball_bounds.left - player_bounds.left) >= -60 && (ball_bounds.left - player_bounds.left) <= 30;
		bool col_y = (ball_bounds.top - player_bounds.top) >= -60 && (ball_bounds.top - player_bounds.top) <= 30;
		
		if (col_x && (ball_bounds.left >= player_bounds.left + (player_bounds.width/2) || ball_bounds.left <= player_bounds.left - (player_bounds.width+3))) {
			my_ball.collision_x();
		}
		else if (col_y) {
			my_ball.collision_y();
		}
		else {
			my_ball.collision();
		}
	}

}


void windowHandler::move() {
	for (const auto& action : actions) {
		if (sf::Keyboard::isKeyPressed(action.Key)) {
			my_player.move(sf::Vector2f{ action.x, action.y });
		}
	}
	my_ball.move();
}



