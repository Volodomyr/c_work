#include "..\inc\GameState.hpp"

GameState::GameState(sf::RenderWindow& _window) {
	box = new Box;
	box->SetPosition(200, 200);
}

void GameState::Update(sf::Event e, sf::RenderWindow& window, float time) {

}

void GameState::Draw(sf::RenderWindow &window) {
	box->Draw(window);
}

void GameState::Destroy() {
	delete box;
}
