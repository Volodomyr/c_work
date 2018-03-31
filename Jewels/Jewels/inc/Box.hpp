#pragma once
#ifndef BOX_H
#define BOX_H
#include <SFML\Graphics.hpp>
#include "ResourceManager.hpp"
const float BOX_SIZE = 64.0f; //������ Box

class Box {
protected:
	sf::Vector2f *position;    //���������
	sf::Vector2f *size;		   //������
	sf::RectangleShape *rect;  //�������������� �������������

public:
	Box();
	~Box();
	virtual void SetPosition(float x, float y);  //�-u ������������� ��������� Box
	virtual void SetPosition(const sf::Vector2f& _position);
	virtual void Update(sf::RenderWindow& window, float time); //��������� �������
	virtual void Draw(sf::RenderWindow& window);  //��������� �� �����

	void SetSize(float width, float height);
	void SetRect(const sf::RectangleShape& _rect);
	void SetTexture(const sf::Texture& _texture) { rect->setTexture(&_texture); }
	void Box::SetColor(const sf::Color& color);
	
	sf::Texture GetTexture() { return *rect->getTexture(); }
	sf::Vector2f GetPosition();
	sf::Vector2f GetSize();
	sf::RectangleShape GetRect();
};

#endif //BOX_H