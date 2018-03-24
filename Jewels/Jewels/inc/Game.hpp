#pragma once
#ifndef GAME_HPP
#define GAME_HPP
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Resource.hpp"
#include "MenuState.hpp"
const size_t WINDOW_WIDTH = 640;
const size_t WINDOW_HEIGHT = 480;
constexpr const char *WINDOW_TITLE = "SuperJewels!";

class Game {

public:
	enum STATE {
		PLAY = 1,
		PAUSE,
		MENU,
		CLOSE
	}; // ��������� ����

	sf::RenderWindow *gameWindow;
	STATE gameState;
	MenuState *menu;

	//Menu gameMenu(&gameWindow);

	/*
	��� ������� �������
	+ ��������� ���� � �.�
	*/

public:
	Game();
	~Game();
	void Run();
	sf::RenderWindow* GetWindow() { return gameWindow; }
	void Update();
	void Pause();
	void ShowMenu();
	void Exit();
};

#endif //GAME_HPP