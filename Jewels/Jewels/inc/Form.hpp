#pragma once
#ifndef FORM_H
#define FORM_H
#include <SFML\Graphics.hpp>
#include "ResourceManager.hpp"
#include "Event.hpp"
const unsigned CHAR_SIZE = 20;


class Form {
protected:
	sf::Vector2f position; //расположение формы
	sf::Vector2f size;		//размер - ширина , высота
	sf::RectangleShape rect;	//фигура, для прорисовки
	sf::Text text;			//текстовое поле формы

public:
	Form();
	virtual void SetPosition(float _x, float _y) = 0; //меняет позицию формы
	virtual void Update(const sf::RenderWindow& window) = 0; //обработка событий
	virtual void Draw(sf::RenderTarget& renderer) = 0; //прорисовка
	bool isPointed(const sf::RenderWindow& window);	//проверка на наведение
	bool isClicked(const sf::RenderWindow& window); //проверка на клик

	sf::Vector2f getSize() const;
};

#endif //FORM_H