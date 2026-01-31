#include"Food.h"
void Food::draw(sf::RenderWindow& window) const {
	sf::RectangleShape rectShape;
	rectShape.setSize(sf::Vector2f(tileSize, tileSize));
	rectShape.setFillColor(sf::Color::Red);
	rectShape.setPosition(static_cast<float>(pos.x * tileSize), static_cast<float>(pos.y * tileSize));
	window.draw(rectShape);
}
void Food::generate() {
	sf::Vector2i position(rand() % (800 / (int)tileSize), rand() % (600 / (int)tileSize));
	pos = position;
}
sf::Vector2i Food::getPos() const {
	return pos;
}