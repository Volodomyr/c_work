#include "..\inc\Text.hpp"

Text::Text() {
	value = "m_text";
	text = new sf::Text;
	text->setString(value);
	text->setFont(resMng->getFont("helsinki"));
	text->setCharacterSize(DEFAULT_CHAR_SIZE);

	position = new sf::Vector2f;
}

Text::Text(const std::string& _value, unsigned size) {
	value = _value;
	text = new sf::Text;
	text->setString(value);
	text->setFont(resMng->getFont("helsinki"));
	text->setCharacterSize(size);
	text->setOutlineThickness(1);

	position = new sf::Vector2f;
}

Text::~Text() {
	delete text;
	delete position;
}

void Text::SetString(const std::string& _value) {
	value = _value;
}

void Text::SetCharacterSize(unsigned int size) {
	text->setCharacterSize(size);
}

void Text::SetFont(const sf::Font& font) {
	text->setFont(font);
}

std::string Text::GetString() {
	return value;
}

unsigned int Text::GetCharacterSize() {
	return text->getCharacterSize();
}

sf::Font Text::GetFont() {
	return *text->getFont();
}

void Text::Draw(sf::RenderWindow& window) {
	window.draw(*text);
}

void Text::Update() {
	text->setString(value);
}

void Text::SetPosition(const sf::Vector2f& _position) {
	*position = _position;
	text->setPosition(*position);
}

sf::Vector2f Text::GetPosition() {
	return *position;
}