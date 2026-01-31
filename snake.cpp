#include<SFML/Graphics.hpp>

#include"Snake.h"
void Snake::handleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		direction = { 0,-1 };
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		direction = { 0,1 };
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		direction = { -1,0 };
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		direction = { 1,0 };
}
void Snake::moveSnake() {
	sf::Vector2i newHead = body[0] + direction;
	body.insert(body.begin(), newHead);
	body.pop_back();
}
void Snake::draw(sf::RenderWindow& window) {
	sf::RectangleShape rectShape;
	rectShape.setSize(sf::Vector2f(tileSize, tileSize));
	rectShape.setFillColor(sf::Color::Green);
	for (const auto& node : body) {
		rectShape.setPosition(static_cast<float>(node.x * tileSize), static_cast<float>(node.y * tileSize));
		window.draw(rectShape);
	}
}
void Snake::grow() {
	sf::Vector2i newHead = body[0] + direction;
	body.insert(body.begin(), newHead);
}
sf::Vector2i Snake::getHeadPos() const {
	return body[0];
}