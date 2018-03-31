#pragma once
#ifndef GAME_STATE_H
#define GAME_STATE_H
#include "State.hpp"
#include <SFML\Graphics.hpp>
#include "Grid.hpp"
#include "Background.hpp"


class GameState: public State {
	Grid *grid;

public:
	GameState(sf::RenderWindow& _window);
	~GameState() { this->Destroy(); }
	void Update(sf::RenderWindow& window, float _time) override;
	void Draw(sf::RenderWindow& window) override;
	void Destroy() override;
};

#endif //GAME_STATE_H