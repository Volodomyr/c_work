#pragma once
#ifndef STATE_H
#define STATE_H
#include <SFML\Graphics.hpp>

class State {
public:
	virtual void Init(sf::RenderWindow *window) = 0; //������� ��� ������������� ��������
	virtual void Draw(sf::RenderWindow *window) = 0; //������� ��� ��������� 
	virtual void Update(sf::Event e, sf::RenderWindow *window) = 0; //��������� �������
	virtual void Destroy(sf::RenderWindow *window) = 0; //������� ���� ���������� - �����
};

#endif // STATE_H