#include "..\inc\GameState.hpp"

GameState::GameState(sf::RenderWindow& _window) {
	game_bg.SetImage("game_bg2");

	grid = new Grid(_window);
	grid->Generate();
	grid->CellDistribute();

	score = new Text("0123456789", 40);
	sf::Vector2f scorePos = sf::Vector2f(0.2f * _window.getSize().x,
		0.3f * _window.getSize().y);
	score->SetPosition(scorePos);
}

void GameState::Update(sf::RenderWindow& window, float _time) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
		grid->Generate();
		grid->CellDistribute();
	}
	grid->Update(window, _time);
}

void GameState::Draw(sf::RenderWindow &window) {
	grid->Draw(window);
	score->Draw(window);
}

void GameState::Destroy() {
	delete grid;
	delete score;
}
