#pragma once
#ifndef TEXT_H
#define TEXT_H
#include <string>
#include <SFML\Graphics.hpp>
#include "ResourceManager.hpp"
#include <sstream>
#include <string>
const unsigned DEFAULT_CHAR_SIZE = 16;

class Text {
	std::string value;
	sf::Text *text;
	sf::Vector2f *position;

public:
	Text();
	Text(const std::string& _value, unsigned size);
	~Text();
	void SetString(const std::string& _value);
	void SetCharacterSize(unsigned int size);
	void SetFont(const sf::Font& font);
	void SetPosition(const sf::Vector2f& _position);
	void SetColor(const sf::Color& color);
	void SetThickness(float thickness);

	static std::string ToString(unsigned value);
	sf::Vector2f GetPosition();
	std::string GetString();
	unsigned int GetCharacterSize();
	sf::Font GetFont();
	sf::FloatRect GetRect();
	virtual void Draw(sf::RenderWindow& window);
	void Update();
};

#endif //TEXT_H