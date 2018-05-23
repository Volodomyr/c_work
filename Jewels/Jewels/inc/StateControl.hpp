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
}; // ��������� ����


class StateControl {
	sf::RenderWindow *window; //��������� �� ����
	State *curr_state; //��������� �� ������� ���������
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
	void Draw();//������� ��� ��������� 
	void Update(float _time = 0.0f); //��������� �������
	void Destroy(); //������� �����
	
};

extern StateControl main_state;
#endif // STATE_CONTROL_H