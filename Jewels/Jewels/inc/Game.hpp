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
constexpr const char *WINDOW_TITLE = "SuperJewels!";

class Game {
	sf::RenderWindow *gameWindow;
	
public:
	Game();
	~Game();
	void Run();
	sf::RenderWindow* GetWindow() { return gameWindow; }
	void Update();
	void Draw();
};

#endif //GAME_HPP