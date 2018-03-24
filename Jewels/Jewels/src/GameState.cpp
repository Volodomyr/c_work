#include "..\inc\GameState.hpp"

void GameState::Init(sf::RenderWindow *window) {
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
