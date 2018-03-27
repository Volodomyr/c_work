#pragma once
#ifndef BOX_H
#define BOX_H
#include <SFML\Graphics.hpp>
const float BOX_SIZE = 64.0f; //размер Box
const sf::Color BOX_COLOR = { 0, 0, 0, 50 };  //цвет фона
const sf::Color BOX_BORDER_COLOR = { 0, 0, 0, 130 }; //цвет контура
const float BOX_BORDER = 2.f; //толщина контура

class Box {
protected:
	sf::Vector2f *position;    //положение
	sf::Vector2f *size;		   //размер
	sf::RectangleShape *rect;  //ограничивающий прямоугольник
	char value;				   //поле значения
	sf::Texture *texture;

public:
	Box();
	~Box();
	virtual void SetPosition(float x, float y);      //ф-я устанавливает положение Box
	virtual void Update(sf::Event e, float time);   //обработка событий
	virtual void Draw(sf::RenderWindow& window);  //отрисовка на экран

	void SetSize(float width, float height);
	void SetRect(const sf::RectangleShape& _rect);
	void SetValue(char _value);

	sf::Vector2f GetPosition();
	sf::Vector2f GetSize();
	sf::RectangleShape GetRect();
	char GetValue();
};
















#endif //BOX_H