#include "..\inc\Form.hpp"

Form::Form() {
	text.setCharacterSize(CHAR_SIZE);
	text.setOutlineColor(sf::Color::Black);
	text.setFillColor(sf::Color::White);
	text.setFont(resMngr->fonts.Get("arial"));
}

bool Form::isPointed(const sf::RenderWindow& window) {
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
	return rect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse_pos));
}

bool Form::isClicked(sf::Event e, const sf::RenderWindow& window) {
	if (this->isPointed(window) && e.type == sf::Event::MouseButtonPressed) {
		return (e.mouseButton.button == sf::Mouse::Left);
	}
	return 0;
}

sf::Vector2f Form::getSize() const {
	return rect.getSize();
}
