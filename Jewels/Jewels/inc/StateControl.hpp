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
}; // ��������� ����


class StateControl {
	sf::RenderWindow *window; //��������� �� ����
	State *curr_state; //��������� �� ������� ���������

public:
	StateControl();
	~StateControl();

	void SetWindow(sf::RenderWindow* _window);
	void SetState(State *_state);
	sf::RenderWindow* GetWindow() { return window; }
	State& GetState() { return *curr_state; }

	void SwitchState(const STATE& new_state);
	void Draw();//������� ��� ��������� 
	void Update(sf::Event& event); //��������� �������
	void Destroy(); //������� �����
	
};

extern StateControl main_state;
#endif // STATE_CONTROL_H