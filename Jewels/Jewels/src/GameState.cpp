#include "..\inc\GameState.hpp"

GameState::GameState(sf::RenderWindow *_window) {
	circle = new sf::CircleShape(200.0f);
	circle->setFillColor(sf::Color::Red);
}

void GameState::Update(sf::Event e, sf::RenderWindow *window) {

}

void GameState::Draw(sf::RenderWindow *window) {
	window->draw(*circle);
}

void GameState::Destroy(sf::RenderWindow *window) {
	delete circle;
}
