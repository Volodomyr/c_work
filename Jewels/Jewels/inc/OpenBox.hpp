#pragma once
#ifndef OPEN_BOX_H
#define OPEN_BOX_H
#include "Box.hpp"

#include <SFML\Graphics.hpp>
#include "ResourceManager.hpp"
#include <cmath>
#include <iostream>
#include "Event.hpp"

const sf::Color BOX_COLOR = { 0, 0, 0, 50 };  //цвет фона
const sf::Color BOX_BORDER_COLOR = { 0, 0, 0, 130 }; //цвет контура
const float BOX_BORDER = 2.f; //толщина контура
const float MOVE_SPEED = 120.f;

enum DIRECTION {
	LEFT = -2,
	UP,
	NONE,
	DOWN,
	RIGHT
};

class OpenBox : public Box {
	unsigned short value; //поле значения
	sf::Sprite *sprite;

	float offset;
	DIRECTION direction;
	bool swap_state;
	bool match;
	bool moved;


public:
	OpenBox();
	~OpenBox();
	void SetPosition(float x, float y) override;      //ф-я устанавливает положение Box
	void Update(sf::RenderWindow& window, float time) override;   //обработка событий
	void Draw(sf::RenderWindow& window) override;  //отрисовка на экран
	bool inMotion() { return offset != 0; }
	bool isFill() { return value != 0; }
	void BackToOrigin();
	
	bool operator==(const OpenBox& other) { return value == other.value; }
	bool operator!=(const OpenBox& other) { return !(*this == other); }

	void Move(float time);
	void Slide(DIRECTION _dir);
	bool isClicked(sf::RenderWindow& window);
	void SetValue(unsigned short _value);
	void SetTexture(const sf::Texture& _texture);
	void SetTexture(const sf::Texture& _texture, const sf::IntRect& _rect);
	void SetSprite(const sf::Sprite& _sprite) { *sprite = _sprite; }
	void SetDirection(DIRECTION _dir);
	void SetSwapState(bool _swapState) { swap_state = _swapState; }
	void SetMoved(bool _moved) { moved = _moved; }
	void SetMatch(bool _match);

	bool GetMatch();
	bool GetSwapState() { return swap_state; }
	bool GetMoved() { return moved; }
	DIRECTION GetDirection() { return direction; }
	sf::Sprite& GetSprite() { return *sprite; }
	sf::Vector2f GetOffset(DIRECTION dir, float time);
	sf::Texture GetTexture();
	unsigned short GetValue();
};

#endif //OPEN_BOX_H

