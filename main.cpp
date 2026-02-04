#include<SFML/Graphics.hpp>
#include<vector>
#include<iostream>
#include"Snake.h"
#include"Food.h"
constexpr auto TILESIZE = 20.0f;
int main() {
	srand((unsigned)time(NULL));
	// 初始化窗口
	sf::RenderWindow window(sf::VideoMode(windX, windY), "SFML_Snake");

	//初始化蛇
	Snake snake(sf::Vector2i(10, 10), TILESIZE);

	//初始化食物数组
	std::vector<Food>foods;
	Food firstFood(TILESIZE);
	foods.push_back(firstFood);
	foods[0].generate();

	sf::Clock clock;
	float timer = 0.0f;
	float delay = 0.2f;
	//主循环
	while (window.isOpen()) {
		// 获取两帧之间时间差
		float dt = clock.restart().asSeconds();
		timer += dt;
		//处理输入
		snake.handleInput();
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		// 逻辑更新
		if (timer > delay) {
			snake.moveSnake();
			timer = 0;
		}

		if (snake.getHeadPos() == foods[0].getPos()) {
			foods.pop_back();
			Food newFood(TILESIZE);
			newFood.generate();
			foods.push_back(newFood);

			snake.grow();
		}
		if (snake.checkSelfCollision()) {
			std::cout << "Game Over" << std::endl;
			break;
		}

		// 渲染
		window.clear();
		snake.draw(window);
		for (auto& food : foods)
			food.draw(window);
		window.display();
	}
	return 0;
}