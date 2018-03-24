#pragma once
#ifndef MENU_H
#define MENU_H

#include <list>
#include <SFML\Graphics.hpp>
#include "Button.hpp"

class Game;

enum Item { START, OPTIONS, ACHIEVEMENTS, INFORMATION, EXIT };
const size_t BTN_COUNT = 5; //количество кнопок
const size_t BTN_SPACE = 18; // рассто€ние между кнопками
const size_t OFFSET = 20;

class MenuState {
	Game *game;
	sf::RectangleShape background;
	sf::Vector2f pos;
	sf::Vector2f size;
	std::list<Button> items;

public:
	MenuState(Game* _game);
	void Update(sf::Event e, const sf::RenderWindow& _window);
	void SetPos(float x, float y);
	void SetSize(const sf::Vector2f& _size);

	sf::Vector2f& GetPos() { return pos; }
	sf::Vector2f& GetSize() { return size; }
	void Draw(sf::RenderTarget& _window);
};

#endif //MENU_H