#pragma once
#ifndef STATE_H
#define STATE_H
#include <SFML\Graphics.hpp>

class State {

public:
	virtual void Draw(sf::RenderWindow& window) = 0; //������� ��� ��������� 
	virtual void Update(sf::Event e, sf::RenderWindow& window, float time = 0.0f) = 0; //��������� �������
	virtual void Destroy() = 0; //������� ���� ���������� - �����
};

#endif // STATE_H