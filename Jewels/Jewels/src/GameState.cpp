#include "..\inc\GameState.hpp"

GameState::GameState(sf::RenderWindow& _window) {
	game_bg.SetImage("game_bg2");

	grid = new Grid(_window);
	grid->Generate();
}

void GameState::Update(sf::RenderWindow& window, float _time) {
	grid->Update(window, _time);
}

void GameState::Draw(sf::RenderWindow &window) {
	grid->Draw(window);
}

void GameState::Destroy() {
	delete grid;
}
