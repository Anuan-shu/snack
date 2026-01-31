#ifndef FOOD_H
#define FOOD_H
#include<SFML/Graphics.hpp>
class Food {
public:
	Food(sf::Vector2i p, float t) : pos(p), tileSize(t) {};
	Food(float t) : tileSize(t) {};
	Food() = default;
	sf::Vector2i getPos() const;
	void draw(sf::RenderWindow& window) const;
	void generate();
private:
	sf::Vector2i pos;
	float tileSize;
};
#endif // !FOOD_H
