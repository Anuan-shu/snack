#include"game.h"
void Game::run() {
	srand((unsigned)time(NULL));

	while (mWindow.isOpen()) {
		// 获取两帧之间时间差
		float dt = clock.restart().asSeconds();
		this->processEvents();
		this->update(dt);

		this->render();
	}
}
void Game::update(float gt) {
	if (mState != GameState::Playing)return;
	mTimer += gt;
	if (mTimer > mDelay) {
		mSnake.moveSnake();
		mTimer = 0;

		if (mSnake.getHeadPos() == mFoods[0].getPos()) {
			mFoods.pop_back();
			Food newFood(TILESIZE);
			newFood.generate();
			mFoods.push_back(newFood);

			mSnake.grow();
			mScoreText.setString("Score: " + std::to_string(mSnake.score));

			// 加速
			if (mSnake.score < 100) {
				mDelay = 0.2f - (mSnake.score * 0.0005f);
			}
			else if (mSnake.score < 300) {
				mDelay = 0.15f - ((mSnake.score - 100) * 0.0006f);
			}
			else {
				mDelay = 0.03f;
			}
		}
		if (mSnake.checkSelfCollision()) {
			std::cout << "Game Over" << std::endl;
			mState = GameState::GameOver;
			return;
		}
	}
}

void Game::reset() {
	mSnake.reset(sf::Vector2i(10, 10));
	mFoods.clear();
	Food firstFood(TILESIZE);
	mFoods.push_back(firstFood);
	mFoods[0].generate();
	mDelay = 0.2f;
	mTimer = 0;
}
void Game::render() {
	mWindow.clear();

	if (mState == GameState::Menu) {
		mWindow.draw(mMenuText);
	}
	else {
		mSnake.draw(mWindow);
		for (auto& food : mFoods)
			food.draw(mWindow);
		mWindow.draw(mScoreText);

		if (mState == GameState::GameOver) {
			mWindow.draw(mGameOverText);
		}
	}

	mWindow.display();
}
void Game::processEvents() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			mWindow.close();
		}
		// 处理菜单和结束页的按键切换
		if (mState == GameState::Menu && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			mState = GameState::Playing;
		}
		if (mState == GameState::GameOver && sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			reset();
			mState = GameState::Playing;
		}
	}
	// 读取蛇的方向控制
	if (mState == GameState::Playing) {
		mSnake.handleInput();
	}
}