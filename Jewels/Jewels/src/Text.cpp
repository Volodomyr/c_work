#include "..\inc\Text.hpp"

Text::Text() {
	value = "";
	text = new sf::Text;
	text->setString(value.c_str());
	text->setFont(resMng->getFont("helsinki"));
	text->setCharacterSize(DEFAULT_CHAR_SIZE);

	position = new sf::Vector2f;
}

Text::Text(const std::string& _value, unsigned size) {
	value = _value;
	text = new sf::Text;
	text->setString(value.c_str());
	text->setFont(resMng->getFont("helsinki"));
	text->setCharacterSize(size);

	position = new sf::Vector2f;
}

Text::~Text() {
	delete text;
	delete position;
}

void Text::SetString(const std::string& _value) {
	value = _value;
	this->Update();
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
	text->setString(value.c_str());
}

void Text::SetPosition(const sf::Vector2f& _position) {
	*position = _position;
	text->setPosition(*position);
}

std::string Text::ToString(unsigned value)
{
	std::ostringstream ostream;
	ostream << value << std::ends;
	return ostream.str();
}

sf::Vector2f Text::GetPosition() {
	return *position;
}

sf::FloatRect Text::GetRect() {
	return text->getGlobalBounds();
}

void Text::SetColor(const sf::Color& color) {
	text->setFillColor(color);
}

void Text::SetThickness(float thickness) {
	text->setOutlineThickness(thickness);
}