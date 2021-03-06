#pragma once
#ifndef MENU_H
#define MENU_H

#include <list>
#include <SFML\Graphics.hpp>
#include "Button.hpp"
#include "State.hpp"
#include "StateControl.hpp"
#include <iostream>
#include "Background.hpp"

const size_t BTN_COUNT = 3; //���������� ������
const size_t BTN_SPACE = 18; // ���������� ����� ��������
const size_t OFFSET = 20;


class MenuState: public State {
	sf::RectangleShape *menu_panel;
	sf::Vector2f *pos;
	sf::Vector2f *size;
	std::list<Button> items;

public:
	MenuState(sf::RenderWindow& _window);
	~MenuState() { this->Destroy(); }
	void Update(sf::RenderWindow& window, float time) override;
	void Draw(sf::RenderWindow& window) override;
	void Destroy() override;
	
	void SetPos(float x, float y);
	void SetSize(const sf::Vector2f& _size);
	sf::Vector2f& GetPos() { return *pos; }
	sf::Vector2f& GetSize() { return *size; }
};

#endif //MENU_H