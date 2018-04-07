#include "..\inc\Form.hpp"
#include "..\inc\Game.hpp"

Form::Form() {
	text.setCharacterSize(CHAR_SIZE);
	text.setOutlineColor(sf::Color::Black);
	text.setFillColor(sf::Color::White);
	text.setFont(resMng->getFont("domino")); //default font
}

bool Form::isPointed(const sf::RenderWindow& window) {
	return events.isPointed(rect.getGlobalBounds(), window);
}

bool Form::isClicked(const sf::RenderWindow& window) {
	return events.isClicked(rect.getGlobalBounds(), window);
}

sf::Vector2f Form::getSize() const {
	return rect.getSize();
}
