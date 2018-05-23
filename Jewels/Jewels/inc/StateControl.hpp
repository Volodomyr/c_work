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
	INFO,
	CLOSE
}; // состояния игры


class StateControl {
	sf::RenderWindow *window; //указатель на окно
	State *curr_state; //указатель на текущее состояние
	bool isGameClose;

public:
	StateControl();
	~StateControl();

	void SetWindow(sf::RenderWindow* _window);
	void SetState(State *_state);
	sf::RenderWindow* GetWindow() { return window; }
	State& GetState() { return *curr_state; }

	bool isClose() { return isGameClose == true; }
	void SwitchState(const STATE& new_state);
	void Draw();//функции для отрисовки 
	void Update(float _time = 0.0f); //обработка событий
	void Destroy(); //очистка полей
	
};

extern StateControl main_state;
#endif // STATE_CONTROL_H