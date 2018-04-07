#pragma once
#ifndef GAME_HPP
#define GAME_HPP
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Resource.hpp"
#include "MenuState.hpp"
#include "StateControl.hpp"
#include "Background.hpp"
#include "AnimationManager.hpp"
#include "Event.hpp"
#include <list>

const size_t WINDOW_WIDTH = 880;
const size_t WINDOW_HEIGHT = 660;
constexpr char *WINDOW_TITLE = "SuperJewels!";

class Game {
	sf::RenderWindow *gameWindow;
	bool debugMode;
	size_t fpsValue;
	
public:
	Game();
	~Game();
	void Run();
	sf::RenderWindow* GetWindow() { return gameWindow; }

	void Update(float _time);
	void Draw();
};

#endif //GAME_HPP