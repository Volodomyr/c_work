#include "..\inc\Game.hpp"

Game::Game() {
	gameWindow = new sf::RenderWindow();
	gameWindow->create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), (sf::String)WINDOW_TITLE);
	gameState = STATE::MENU;
	menu = nullptr;
}

void Game::Run() {
	while (gameState != STATE::CLOSE) {

		if (gameState == STATE::MENU && menu == NULL) { // если состояние игры = меню И объект не пуст
			menu = new MenuState(this);
		}

		sf::Event event;
		while (gameWindow->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				gameState = STATE::CLOSE;
			}

			switch (gameState) {
			case Game::MENU:
				menu->Update(event, *gameWindow);
				break;
				/*/////////////*/
			}

			/*обработка нажатий*/
		}

		//updates
		gameWindow->clear(sf::Color::Blue);
		//gameWindow->draw();
		if (gameState == Game::MENU) {
			menu->Draw(*gameWindow);
		}

		gameWindow->display();
	}

}

Game::~Game() {
	if (gameWindow->isOpen()) {
		this->Exit();
	}
	delete gameWindow;
}

void Game::Pause() {

}

void Game::ShowMenu() {
	gameState = Game::MENU;
}

void Game::Update() {

}

void Game::Exit() {
	gameWindow->close();
}