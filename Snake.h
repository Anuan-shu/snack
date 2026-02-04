#ifndef Snake_H
#define Snake_H
#include<vector>
#include<SFML/Graphics.hpp>
#include<iostream>
enum class EnumDirection {
	UP, DOWN, LEFT, RIGHT
};
constexpr unsigned int windX = 800;
constexpr unsigned int windY = 600;
class Snake {
	using snakeBody = std::vector<sf::Vector2i>;
	snakeBody body;
	sf::Vector2i direction;
	sf::Vector2i lastDirection;
	float tileSize; // 每一格的大小
	bool shouldGrow = false;
public:
	// 构造函数：传入初始位置和格点大小
	Snake(sf::Vector2i startPos, float size) {
		body.push_back(startPos);
		tileSize = size;
	};

	void handleInput();
	void moveSnake();
	void grow();

	bool checkSelfCollision() const;
	bool checkWindCollisionLeft()const;
	bool checkWindCollisionRight()const;
	bool checkWindCollisionUp()const;
	bool checkWindCollisionDown()const;

	bool checkOtherCollision() const;
	sf::Vector2i getHeadPos() const;

	//渲染
	void draw(sf::RenderWindow& window);

};


#endif
