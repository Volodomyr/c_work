#include "..\inc\Game.hpp"
StateControl main_state;

Game::Game() {
	gameWindow = new sf::RenderWindow();
	gameWindow->create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), (sf::String)WINDOW_TITLE);
	main_state.SetWindow(gameWindow);
	main_state.SwitchState(STATE::MENU);
}

void Game::Run() {
	while (!main_state.isClose()) {
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
			main_state.SwitchState(STATE::CLOSE);
		}

		main_state.Update(event);
	}
}

void Game::Draw() {
	gameWindow->clear(sf::Color::Blue);
	main_state.Draw();
	gameWindow->display();
}