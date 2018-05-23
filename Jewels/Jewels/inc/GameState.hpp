#pragma once
#ifndef GAME_STATE_H
#define GAME_STATE_H
#include "State.hpp"
#include <SFML\Graphics.hpp>
#include "Grid.hpp"
#include "Background.hpp"
#include "Text.hpp"
#include <fstream>
#include <sstream>
#include "StateControl.hpp"
const float TIME_MAX = 3; //minutes
const unsigned FONT_SIZE = 16;
const unsigned SCORE_FOR_CELL = 15;

class GameState : public State {
	Grid *grid;
	Text *scoreText;
	Text *maxScoreText;
	Text *timerText;
	unsigned scoreValue;
	unsigned maxScore;
	sf::Clock timer;
	sf::RectangleShape *textBlock;
	bool gamePlay;
	bool valueFixed;
	Text *textEnd;

public:
	GameState(sf::RenderWindow& _window);
	~GameState() { this->Destroy(); }
	void Update(sf::RenderWindow& window, float _time) override;
	void Draw(sf::RenderWindow& window) override;
	void Destroy() override;
};

#endif //GAME_STATE_H