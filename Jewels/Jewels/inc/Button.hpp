#pragma once
#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "SFML\Graphics.hpp"
#include "Form.hpp"
#include <functional>
#include <string>

using func_type = std::function<void()>;
const float M_TEXT_THICK = 2.0f;
const size_t M_TEXT_SIZE = 25;


enum ButtonSize {
	Small,
	Medium,
	Large
};

class Button : public Form {
	func_type function;
	bool isSelected;

	void UpdateText();
	sf::Vector2f SelectSize(ButtonSize btnSize);

public:
	Button();
	Button(const std::string& _text, const sf::Texture& _texture,
		func_type _func, ButtonSize btnSize = Medium);
	void SetFunction(func_type _function);
	void SetTexture(const sf::Texture& _texture);
	void SetText(const std::string& _text);

	void SetPosition(float _x, float _y);
	void Update(const sf::RenderWindow& window);
	void Draw(sf::RenderTarget& renderer);

};

#endif //BUTTON_HPP