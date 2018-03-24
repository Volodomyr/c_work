#pragma once
#ifndef GAME_STATE_H
#define GAME_STATE_H
#include "State.hpp"
#include <SFML\Graphics.hpp>

class GameState: public State {
	/*
	*/
	sf::CircleShape *circle;
public:
	GameState() {}
	void Init(sf::RenderWindow *window);
	void Update(sf::Event e, sf::RenderWindow *window);
	void Draw(sf::RenderWindow *window);
	void Destroy(sf::RenderWindow *window);
};

#endif //GAME_STATE_H