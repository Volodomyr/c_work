#include "..\inc\Box.hpp"

Box::Box() {
	position = new sf::Vector2f;
	*position = sf::Vector2f(0.0f, 0.0f);

	size = new sf::Vector2f;
	*size = sf::Vector2f(BOX_SIZE, BOX_SIZE);

	rect = new sf::RectangleShape;
	rect->setPosition(*position);
	rect->setSize(*size);
	rect->setFillColor(sf::Color::White); //цвет куба по-умолчанию
}

Box::~Box() {
	delete position;
	delete size;
	delete rect;
}

void Box::SetPosition(float x, float y) {
	*position = sf::Vector2f(x, y);
	rect->setPosition(*position);
}

void Box::SetPosition(const sf::Vector2f& _position) {
	*position = _position;
	rect->setPosition(*position);
}

void Box::SetColor(const sf::Color& color) {
	rect->setFillColor(color);
}

void Box::Update(sf::RenderWindow& window, float time) {
	/*if (this->isClicked(window)) {
	selectLayer = new sf::Sprite;
	selectLayer->setPosition(*position);
	selectLayer->setTexture(resMngr->textures.Get("box_select"));
	}*/
}

void Box::Draw(sf::RenderWindow& window) {
	window.draw(*rect);
}

void Box::SetSize(float width, float height) {
	*size = sf::Vector2f(width, height);
	rect->setSize(*size);
}

void Box::SetRect(const sf::RectangleShape& _rect) {
	*rect = _rect;
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
