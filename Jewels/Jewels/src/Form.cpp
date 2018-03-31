#include "..\inc\Form.hpp"
#include "..\inc\Game.hpp"

Form::Form() {
	text.setCharacterSize(CHAR_SIZE);
	text.setOutlineColor(sf::Color::Black);
	text.setFillColor(sf::Color::White);
	text.setFont(resMng->fonts.Get("domino")); //default font
}

bool Form::isPointed(const sf::RenderWindow& window) {
	return events.isPointed(rect.getGlobalBounds(), window);
	/*sf::Vector2i mouse_pos;
	if (window.isOpen()) {
		mouse_pos = sf::Mouse::getPosition(window);
		return rect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse_pos));
	}
	return false;*/
}

bool Form::isClicked(const sf::RenderWindow& window) {
	/*if (this->isPointed(window) && game_event.type == sf::Event::MouseButtonPressed) {
		return (game_event.mouseButton.button == sf::Mouse::Left);
	}
	return false;*/
	return events.isClicked(rect.getGlobalBounds(), window);
}

sf::Vector2f Form::getSize() const {
	return rect.getSize();
}
