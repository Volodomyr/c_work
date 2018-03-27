#include "..\inc\Box.hpp"

Box::Box() {
	position = new sf::Vector2f;
	*position = sf::Vector2f(0.0f, 0.0f);

	size = new sf::Vector2f;
	*size = sf::Vector2f(BOX_SIZE, BOX_SIZE);

	rect = new sf::RectangleShape;
	rect->setPosition(*position);
	rect->setSize(*size);
	rect->setFillColor(BOX_COLOR); //ставим черный полупрозрачный цвет
	rect->setOutlineThickness(BOX_BORDER);
	rect->setOutlineColor(BOX_BORDER_COLOR);

	texture = new sf::Texture;

	value = '0';
}

Box::~Box() {
	delete position;
	delete size;
	delete rect;
	delete texture;
}

void Box::SetPosition(float x, float y) {
	*position = sf::Vector2f(x, y);
	rect->setPosition(*position);
}

void Box::Update(sf::Event e, float time) {

}

void Box::Draw(sf::RenderWindow& window)  {
	window.draw(*rect);
}


void Box::SetSize(float width, float height) {
	*size = sf::Vector2f(width, height);
	rect->setSize(*size);
}

void Box::SetRect(const sf::RectangleShape& _rect) {
	*rect = _rect;
}

void Box::SetValue(char _value) {
	value = _value;
}

sf::Vector2f Box::GetPosition() {
	return *position;
}

sf::Vector2f Box::GetSize() {
	return *size;
}

sf::RectangleShape Box::GetRect() {
	return *rect;
}

char Box::GetValue() {
	return value;
}