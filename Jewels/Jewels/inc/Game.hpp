#pragma once
#ifndef GAME_HPP
#define GAME_HPP
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Resource.hpp"
#include "MenuState.hpp"
#include "StateControl.hpp"
const size_t WINDOW_WIDTH = 880;
const size_t WINDOW_HEIGHT = 660;
const size_t FPS_MAX = 60;
constexpr const char *WINDOW_TITLE = "SuperJewels!";

class Game {
	sf::RenderWindow *gameWindow;
	bool debugMode;
	size_t fpsValue;

	float z;
	
public:
	Game();
	~Game();
	void Run();
	sf::RenderWindow* GetWindow() { return gameWindow; }
	void Update(float _time);
	void Draw();
};

#endif //GAME_HPP