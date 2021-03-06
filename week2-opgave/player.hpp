
#include <SFML/Graphics.hpp>
#include <iostream>

class player{
private:
	sf::RenderWindow & window;
	sf::Vector2f windowSize = window.getView().getSize();
	sf::Vector2f size = { 30,30 };
	sf::Vector2f position;
	sf::RectangleShape rectangle;

	bool col = false;
	

public:
	player(sf::RenderWindow & window, sf::Vector2f size = { 30,30 });
	void draw() const;
	sf::Vector2f move(sf::Vector2f delta);
	sf::FloatRect get_player_bounds();
	void collision();
};
