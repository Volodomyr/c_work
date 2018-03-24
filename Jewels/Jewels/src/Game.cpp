#include "..\inc\Game.hpp"
StateControl main_state;

Game::Game() {
	gameWindow = new sf::RenderWindow();
	gameWindow->create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), (sf::String)WINDOW_TITLE);
	gameState = STATE::MENU;
	main_state.SetWindow(gameWindow);
	main_state.SwitchState(gameState);
}

void Game::Run() {
	while (gameWindow->isOpen()) {
		this->Update();
		this->Draw();
	}
}

Game::~Game() {
	if (gameWindow->isOpen()) {
		gameWindow->close();
	}
	delete gameWindow;
}

void Game::Update() {
	sf::Event event;
	while (gameWindow->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			gameState = STATE::CLOSE;
		}

		main_state.Update(event);

		/*обработка нажатий*/
	}
}

void Game::Draw() {
	gameWindow->clear(sf::Color::Blue);
	main_state.Draw();
	gameWindow->display();
}