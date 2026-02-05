#pragma once
#include <SFML/Graphics.hpp>
#include "snake.h"
#include "food.h"
constexpr auto TILESIZE = 20.0f;
constexpr auto FONTSIZE = 24;
enum class GameState { Menu, Playing, GameOver };

class Game {
public:
	Game() :mWindow(sf::VideoMode(windX, windY), "SFML_Snake"),
		mSnake(sf::Vector2i(10, 10), TILESIZE),
		mState(GameState::Playing),
		mTimer(0.0f),
		mDelay(0.2f) {
		// 加载字体
		if (!mFont.loadFromFile("GB2312.ttf")) {
			std::cout << "加载字体错误" << std::endl;
		}
		// 创建文字对象
		mScoreText.setFont(mFont);
		mScoreText.setCharacterSize(FONTSIZE);
		mScoreText.setFillColor(sf::Color::White);
		mScoreText.setPosition(10.f, 10.f);
		mGameOverText.setFont(mFont);
		mGameOverText.setCharacterSize(FONTSIZE);
		mGameOverText.setFillColor(sf::Color::Red);
		mGameOverText.setPosition(350.f, 250.f);
		mGameOverText.setString("Game Over!");
		mMenuText.setFont(mFont);
		mMenuText.setCharacterSize(FONTSIZE);
		mMenuText.setFillColor(sf::Color::White);
		mMenuText.setPosition(10.f, 10.f);

		//初始化食物数组
		Food firstFood(TILESIZE);
		mFoods.push_back(firstFood);
		mFoods[0].generate();
	};             // 初始化窗口、字体、对象
	void run();         // 启动主循环

private:
	void processEvents();
	void update(float dt);
	void render();
	void reset();       // 重置游戏数据

	sf::RenderWindow mWindow;
	GameState mState;

	// 资源
	sf::Font mFont;
	sf::Text mMenuText;
	sf::Text mScoreText;
	sf::Text mGameOverText;

	// 游戏对象
	Snake mSnake;
	std::vector<Food> mFoods;

	sf::Clock clock;
	float mTimer;
	float mDelay;
};
