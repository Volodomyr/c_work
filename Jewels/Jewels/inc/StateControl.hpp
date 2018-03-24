#pragma once
#ifndef STATE_CONTROL_H
#define STATE_CONTROL_H
#include <SFML\Graphics.hpp>
#include "State.hpp"
#include "GameState.hpp"
#include "MenuState.hpp"

enum STATE {
	PLAY = 1,
	PAUSE,
	MENU,
	SETTINGS,
	CLOSE
}; // состояния игры


class StateControl {
	sf::RenderWindow *window; //указатель на окно
	State *curr_state; //указатель на текущее состояние

public:
	StateControl();
	~StateControl();

	void SetWindow(sf::RenderWindow* _window);
	void SetState(State *_state);
	sf::RenderWindow* GetWindow() { return window; }
	State& GetState() { return *curr_state; }

	void SwitchState(const STATE& new_state);
	void Draw();//функции для отрисовки 
	void Update(sf::Event& event); //обработка событий
	void Destroy(); //очистка полей
	
};

extern StateControl main_state;
#endif // STATE_CONTROL_H