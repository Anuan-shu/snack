#ifndef Snake_H
#define Snake_H
#include<vector>
#include<SFML/Graphics.hpp>
enum class EnumDirection {
	UP, DOWN, LEFT, RIGHT
};
class Snake {
	using snakeBody = std::vector<sf::Vector2i>;
	snakeBody body;
	sf::Vector2i direction;
	float tileSize; // 每一格的大小
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
	bool checkOtherCollision() const;
	sf::Vector2i getHeadPos() const;

	//渲染
	void draw(sf::RenderWindow& window);

};


#endif
