#pragma once
#ifndef STATE_H
#define STATE_H
#include <SFML\Graphics.hpp>

class State {

public:
	virtual void Draw(sf::RenderWindow& window) = 0; //функции для отрисовки 
	virtual void Update(sf::Event e, sf::RenderWindow& window, float time = 0.0f) = 0; //обработка событий
	virtual void Destroy() = 0; //очистка всех указателей - полей
};

#endif // STATE_H