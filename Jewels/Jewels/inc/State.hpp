#pragma once
#ifndef STATE_H
#define STATE_H
#include <SFML\Graphics.hpp>

class State {
public:
	virtual void Init(sf::RenderWindow *window) = 0; //функция для инициализации значений
	virtual void Draw(sf::RenderWindow *window) = 0; //функции для отрисовки 
	virtual void Update(sf::Event e, sf::RenderWindow *window) = 0; //обработка событий
	virtual void Destroy(sf::RenderWindow *window) = 0; //очистка всех указателей - полей
};

#endif // STATE_H