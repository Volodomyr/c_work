#pragma once
#ifndef BOX_H
#define BOX_H
#include <SFML\Graphics.hpp>
const float BOX_SIZE = 64.0f; //������ Box
const sf::Color BOX_COLOR = { 0, 0, 0, 50 };  //���� ����
const sf::Color BOX_BORDER_COLOR = { 0, 0, 0, 130 }; //���� �������
const float BOX_BORDER = 2.f; //������� �������

class Box {
protected:
	sf::Vector2f *position;    //���������
	sf::Vector2f *size;		   //������
	sf::RectangleShape *rect;  //�������������� �������������
	char value;				   //���� ��������
	sf::Texture *texture;

public:
	Box();
	~Box();
	virtual void SetPosition(float x, float y);      //�-� ������������� ��������� Box
	virtual void Update(sf::Event e, float time);   //��������� �������
	virtual void Draw(sf::RenderWindow& window);  //��������� �� �����

	void SetSize(float width, float height);
	void SetRect(const sf::RectangleShape& _rect);
	void SetValue(char _value);

	sf::Vector2f GetPosition();
	sf::Vector2f GetSize();
	sf::RectangleShape GetRect();
	char GetValue();
};
















#endif //BOX_H