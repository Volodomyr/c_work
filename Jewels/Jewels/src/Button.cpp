#include "..\inc\Button.hpp"

void Button::Update() {
	text.setOrigin(text.getGlobalBounds().width / 2.0f,
		text.getGlobalBounds().height / 2.0f);	//меняем центр текста с 0, 0 - на полов. ширины и высоты

	text.move(rect.getGlobalBounds().width / 2.0f,	// двигаем текст в центр кнопки
		rect.getGlobalBounds().height / 2.0f);
}

sf::Vector2f Button::SelectSize(ButtonSize btnSize)
{
	sf::Vector2f _size;
	switch (btnSize) {
	case ButtonSize::Small:
		_size = { 128, 64 };
		break;
	case ButtonSize::Medium:
		_size = { 262, 64 };
		break;
	case ButtonSize::Large:
		_size = { 512, 128 };
		break;
	}
	return _size;
}

Button::Button() {
	this->SetText("Button");
	this->SetTexture(resMngr->textures.Get("btn"));
	this->SetFunction(nullptr);
	rect.setFillColor(sf::Color::White);
	rect.setSize(this->SelectSize(ButtonSize::Medium));
	text.setOutlineColor(sf::Color(27, 120, 154));
	text.setOutlineThickness(M_TEXT_THICK);
	text.setCharacterSize(M_TEXT_SIZE);
}

Button::Button(const std::string& _text, const sf::Texture& _texture,
	func_type _func, ButtonSize btnSize)
{
	this->SetText(_text);
	this->SetTexture(_texture);
	this->SetFunction(_func);

	rect.setFillColor(sf::Color::White);
	rect.setSize(this->SelectSize(btnSize));
}

void Button::SetFunction(func_type _function) {
	function = _function;
}

void Button::SetTexture(const sf::Texture& _texture) {
	rect.setTexture(&_texture);
}

void Button::SetText(const std::string& _text) {
	text.setString(_text);
	this->Update();
}

void Button::SetPosition(float _x, float _y) {
	this->position = sf::Vector2f(_x, _y);
	rect.setPosition(this->position);
	text.setPosition(this->position);
	this->Update();
}

void Button::HandleEvent(sf::Event e, const sf::RenderWindow& window) {

	if (this->isPointed(window)) {
		if (!isSelected) {
			isSelected = true;
			text.setFillColor(sf::Color::Green); // подстветка
		}
	}
	else {
		isSelected = false;
		text.setFillColor(sf::Color::White);
	}

	if (this->isClicked(e, window)) {
		function();
	}
}

void Button::Draw(sf::RenderTarget& renderer) {
	renderer.draw(rect);
	renderer.draw(text);
}
