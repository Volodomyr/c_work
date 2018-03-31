#pragma once
#ifndef FORM_H
#define FORM_H
#include <SFML\Graphics.hpp>
#include "ResourceManager.hpp"
#include "Event.hpp"
const unsigned CHAR_SIZE = 20;


class Form {
protected:
	sf::Vector2f position; //������������ �����
	sf::Vector2f size;		//������ - ������ , ������
	sf::RectangleShape rect;	//������, ��� ����������
	sf::Text text;			//��������� ���� �����

public:
	Form();
	virtual void SetPosition(float _x, float _y) = 0; //������ ������� �����
	virtual void Update(const sf::RenderWindow& window) = 0; //��������� �������
	virtual void Draw(sf::RenderTarget& renderer) = 0; //����������
	bool isPointed(const sf::RenderWindow& window);	//�������� �� ���������
	bool isClicked(const sf::RenderWindow& window); //�������� �� ����

	sf::Vector2f getSize() const;
};

#endif //FORM_H