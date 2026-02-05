#include<SFML/Graphics.hpp>

#include"Snake.h"

void Snake::handleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (lastDirection.y != 1)
			direction = { 0,-1 };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (lastDirection.y != -1)
			direction = { 0,1 };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (lastDirection.x != 1)
			direction = { -1,0 };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (lastDirection.x != -1)
			direction = { 1,0 };
	}
}
void Snake::moveSnake() {
	lastDirection = direction;
	sf::Vector2i newHead = body[0] + direction;
	if (newHead.y >= windY / tileSize) {
		std::cout << "Down" << std::endl;
		newHead.y = 0;
	}
	else if (newHead.x < 0) {
		std::cout << "Left" << std::endl;
		newHead.x = (windX / tileSize) - 1;
	}
	else if (newHead.x >= windX / tileSize) {
		std::cout << "Right" << std::endl;
		newHead.x = 0;
	}
	else if (newHead.y < 0) {
		std::cout << "Up" << std::endl;
		newHead.y = (windY / tileSize) - 1;
	}
	body.insert(body.begin(), newHead);
	if (!shouldGrow)
		body.pop_back();
	else
		shouldGrow = false;
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
	shouldGrow = true;
	score += 10;
}

void Snake::reset(sf::Vector2i startPos) {
	body.clear();
	score = 0;
	direction = { 0,0 };
	body.push_back(startPos);
}

sf::Vector2i Snake::getHeadPos() const {
	return body[0];
}

bool Snake::checkSelfCollision() const {
	for (size_t i = 1; i < body.size(); i++) {
		if (body[i] == body[0])
			return true;
	}
	return false;
}
bool Snake::checkWindCollisionLeft() const {
	if (body[0].x <= 0)
		return true;
	return false;
}
bool Snake::checkWindCollisionRight()const {
	if (body[0].x >= windX / tileSize)
		return true;
	return false;
}
bool Snake::checkWindCollisionUp()const {
	if (body[0].y <= 0)
		return true;
	return false;
}
bool Snake::checkWindCollisionDown()const {
	if (body[0].y >= windY / tileSize)
		return true;
	return false;
}