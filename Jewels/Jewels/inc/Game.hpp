#pragma once
#ifndef GAME_HPP
#define GAME_HPP
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Resource.hpp"
#include "MenuState.hpp"
#include "StateControl.hpp"
const size_t WINDOW_WIDTH = 640;
const size_t WINDOW_HEIGHT = 480;
constexpr const char *WINDOW_TITLE = "SuperJewels!";

class Game {
public:
	sf::RenderWindow *gameWindow;
	STATE gameState;
	//Menu gameMenu(&gameWindow);

	/*
	Все игровые объекты
	+ посчитать очки и т.д
	*/

public:
	Game();
	~Game();
	void Run();
	sf::RenderWindow* GetWindow() { return gameWindow; }
	void Update();
	void Draw();
};

#endif //GAME_HPP